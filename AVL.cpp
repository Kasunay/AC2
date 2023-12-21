#include "AVL.h"
#include <algorithm>

AVL::AVL() : root(nullptr) {}

AVL::~AVL()
{
    clear();
}

void AVL::insert(const string &key)
{
    root = insert(root, key);
}

bool AVL::search(const string &key) const
{
    return search(root, key) != nullptr;
}

void AVL::clear()
{
    clear(root);
    root = nullptr;
}

AVLNode *AVL::insert(AVLNode *node, const string &key)
{
    if (node == nullptr)
    {
        node = new AVLNode();
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return node;
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->key)
    {
        return rotateRight(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return rotateLeft(node);
    }

    if (balance > 1 && key > node->left->key)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVLNode *AVL::search(AVLNode *node, const string &key) const
{
    if (node == nullptr || node->key == key)
    {
        return node;
    }

    if (node->key < key)
    {
        return search(node->right, key);
    }

    return search(node->left, key);
}

AVLNode *AVL::rotateLeft(AVLNode *node)
{
    AVLNode *y = node->right;
    AVLNode *T2 = y->left;

    y->left = node;
    node->right = T2;

    node->height = max(height(node->left), height(node->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

AVLNode *AVL::rotateRight(AVLNode *node)
{
    AVLNode *y = node->left;
    AVLNode *T2 = y->right;

    y->right = node;
    node->left = T2;

    node->height = max(height(node->left), height(node->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int AVL::height(AVLNode *node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->height;
}

int AVL::balanceFactor(AVLNode *node) const
{
    if (node == nullptr)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

void AVL::clear(AVLNode *node)
{
    if (node != nullptr)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
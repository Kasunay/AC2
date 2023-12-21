#include "BST.h"

using namespace std;

BST::BST() : root(nullptr) {}

BST::~BST()
{
    clear();
}

void BST::insert(const string &key)
{
    root = insert(root, key);
}

bool BST::search(const string &key) const
{
    return search(root, key) != nullptr;
}

void BST::clear()
{
    clear(root);
    root = nullptr;
}

BSTNode *BST::insert(BSTNode *node, const string &key)
{
    if (node == nullptr)
    {
        node = new BSTNode();
        node->key = key;
        node->left = nullptr;
        node->right = nullptr;
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

    return node;
}

BSTNode *BST::search(BSTNode *node, const string &key) const
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

void BST::clear(BSTNode *node)
{
    if (node != nullptr)
    {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
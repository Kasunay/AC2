#ifndef AVL_H
#define AVL_H

#include <string>

using namespace std;

struct AVLNode
{
    string key;
    AVLNode *left;
    AVLNode *right;
    int height;
};

class AVL
{
public:
    AVL();
    ~AVL();
    void insert(const string &key);
    bool search(const string &key) const;
    void clear();

private:
    AVLNode *root;
    AVLNode *insert(AVLNode *AVLNode, const string &key);
    AVLNode *search(AVLNode *AVLNode, const string &key) const;
    AVLNode *rotateLeft(AVLNode *AVLNode);
    AVLNode *rotateRight(AVLNode *AVLNode);
    int height(AVLNode *AVLNode) const;
    int balanceFactor(AVLNode *AVLNode) const;
    void clear(AVLNode *AVLNode);
};

#endif

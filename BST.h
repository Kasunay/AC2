#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

struct BSTNode
{
    string key;
    BSTNode *left;
    BSTNode *right;
};

class BST
{
public:
    BST();
    ~BST();
    void insert(const string &key);
    bool search(const string &key) const;
    void clear();

private:
    BSTNode *root;
    BSTNode *insert(BSTNode *BSTNode, const string &key);
    BSTNode *search(BSTNode *BSTNode, const string &key) const;
    void clear(BSTNode *BSTNode);
};

#endif
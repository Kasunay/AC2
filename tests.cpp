#include "AVL.h"
#include "BST.h"
#include <iostream>

using namespace std;

void testAVLInsertAndSearch() {
    AVL avl;
    avl.insert("apple");
    avl.insert("banana");
    avl.insert("cherry");

    if (avl.search("apple") && avl.search("banana") && avl.search("cherry") && !avl.search("grape")) {
        cout << "AVL insert and search test passed\n";
    } else {
        cout << "AVL insert and search test failed\n";
    }
}

void testBSTInsertAndSearch() {
    BST bst;
    bst.insert("apple");
    bst.insert("banana");
    bst.insert("cherry");

    if (bst.search("apple") && bst.search("banana") && bst.search("cherry") && !bst.search("grape")) {
        cout << "BST insert and search test passed\n";
    } else {
        cout << "BST insert and search test failed\n";
    }
}

int main() {
    testAVLInsertAndSearch();
    testBSTInsertAndSearch();
    return 0;
}
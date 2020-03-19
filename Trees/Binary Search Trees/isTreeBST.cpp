#include<bits/stdc++.h>
#include "../Binary Trees/BinaryTreeClass_int.h"

using namespace std;

bool isTreeBST(node* root) {
    
}

int main() {
    BinaryTree tree;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(8);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(9);
    tree.insertNode(1);
    tree.printLevelOrder();
    node* root = tree.getRoot();

    if(isTreeBST(root))
        printf("Tree is Binary Search Tree\n");
    else
        printf("Not a BST\n");
    
    return 0;
}
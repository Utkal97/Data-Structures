#include<bits/stdc++.h>
#include "BinarySearchTreeClass_int.h"

using namespace std;

node* leastCommonAncestor(node *root, node *node1, node *node2) {
    if(root == NULL || node1 == NULL || node2 == NULL)
        return NULL;
    
    if(node1->data < root->data && node2->data < root->data)
        return leastCommonAncestor(root->left, node1, node2);

    else if(node1->data > root->data && node2->data > root->data) 
        return leastCommonAncestor(root->right, node1, node2);

    else if( (node1->data <= root->data && node2->data >= root->data) ||
            ( node1->data >= root->data && node2->data <= root->data) )
        return root;
}
 
int main() {
    BinarySearchTree tree;
    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(8);
    tree.insertNode(6);
    tree.insertNode(7);
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(9);

    tree.printInorderRecursive();
    tree.printPreOrderRecursive();
    tree.printPostOrderRecursive();
    tree.printLevelOrder();

    node *node1 = tree.findNode(9);
    node *node2 = tree.findNode(8);
    node *root = tree.getRoot();
    node *LCA = leastCommonAncestor(root, node1, node2);
    if(LCA)
        printf("LCA of %d and %d : %d", node1->data, node2->data, LCA->data);
    else
        printf("LCA doesn't exist for %d %d.", node1->data, node2->data);
    return 0;
}
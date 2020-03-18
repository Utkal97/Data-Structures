#include<bits/stdc++.h>
#include "BinaryTreeClass_int.h"
using namespace std;

node* leastCommonAncestor(node* root, node* node1, node* node2) {
    if(root == NULL)
        return NULL;
    else if(root == node1 || root == node2)
        return root;
    
    node* left = leastCommonAncestor(root->left, node1, node2);
    node* right = leastCommonAncestor(root->right, node1, node2);

    if(left && right)
        return root;

    else {
        if(left)
            return left;
        else
            return right;        
    }
}

int main() {
    BinaryTree tree;

    tree.insertNode(1);
    node* Root = tree.getRoot();

    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(7);
    tree.insertNode(8);
    tree.insertNode(9);

    node* n1 = Root->left->left->left;
    node* n2 = Root->right->left;

    node* LCA = leastCommonAncestor(Root, n1, n2);
    cout<<"LCA for "<<n1->data<<" and "<<n2->data<<" : "<<LCA->data<<endl;
    return 0;
}
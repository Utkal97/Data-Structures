#include<bits/stdc++.h>
#include "BinaryTreeClass_int.h"

using namespace std;

bool pathFromRoot(node* root, node* reqd) {
    if(root == NULL)
        return 0;
    
    if(root->left == reqd || root->right == reqd || 
        pathFromRoot(root->left, reqd) ||
        pathFromRoot(root->right, reqd)) {

            printf("%d ", root->data);
            return 1;
    }
    return 0;
}

int main() {
    BinaryTree tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.insertNode(6);
    tree.insertNode(7);
    tree.insertNode(8);
    tree.insertNode(9);

    node* root = tree.getRoot();
    node* reqd = root->left->right;
    cout<<"Path from node to Root is "<< reqd->data<<" ";
    pathFromRoot(root, root->left->right);
    return 0;
}
#include<bits/stdc++.h>
#include "BinarySearchTreeClass_int.h"

using namespace std;

node* createNode(int value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* buildTree(int input[], int start, int end) {
    if(start > end)
        return NULL;
    
    else if(start == end)
        return createNode(input[start]);
    
    int mid = start + (end-start)/2;

    node* root = createNode(input[mid]);
    root->left = buildTree(input, start, mid-1);
    root->right = buildTree(input, mid+1, end);
    return root;
}

node* arrayToBST(int input[], int n) {
    if(n<=0)
        return NULL;
    return buildTree(input, 0, n-1);
}

int main() {
    int input[8] = {1,2,3,4,5,6,7,8};
    node* root = arrayToBST(input,8);
    BinarySearchTree tree;
    tree.setRoot(root);
    cout<<"Inorder : ";
    tree.printInorderRecursive();
    tree.printLevelOrder();
    cout<<endl;
}
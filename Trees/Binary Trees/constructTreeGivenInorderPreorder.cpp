#include<bits/stdc++.h>
#include "BinaryTreeClass_int.h"

using namespace std;

node* createNode(int value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findIndex(string s, int val) {
    int len = s.length();
    for(int i=0; i<len; i++) {
        if(s[i]-48 == val)
            return i;
    }
    return -1;
}

node* constructInorderPreOrder(string inorder, string preorder,
                                 int inorderStart, int inorderEnd, int &preorder_ind) {

    if(inorderStart > inorderEnd)
        return NULL;
    else if(inorderStart == inorderEnd) {
        node* newNode = createNode(preorder[preorder_ind]-48);
        preorder_ind++;
        return newNode;
    }

    node* curr_node = NULL;
    if(preorder_ind < preorder.length()) {
        curr_node = createNode(preorder[preorder_ind]-48);
        int inorder_ind = findIndex(inorder, preorder[preorder_ind]-48);
        preorder_ind++;
        curr_node->left = constructInorderPreOrder(inorder, preorder, inorderStart, inorder_ind-1, preorder_ind);
        curr_node->right = constructInorderPreOrder(inorder, preorder, inorder_ind+1, inorderEnd, preorder_ind);
    }
    return curr_node;
}

node* constructTreeInorderPreorder(string inorder, string preorder) {
    if( inorder.length() != preorder.length() || 
        inorder.length()==0 )
        return NULL;
    
    int inorderStart = 0, inorderEnd = inorder.length()-1, preorder_ind = 0;
    node* newRoot = constructInorderPreOrder(inorder, preorder,
                                             inorderStart, inorderEnd, 
                                             preorder_ind);

    return newRoot;
}

int main() {
    string inorder = "425163", preorder = "124536";
    node* root = constructTreeInorderPreorder(inorder, preorder);

    BinaryTree tree;
    tree.setRoot(root);

    cout<<"Level order : ";
    tree.printLevelOrder();
    cout<<endl;

    cout<<"Inorder : ";
    tree.printInorderRecursive(root);
    cout<<endl;

    cout<<"Preorder : ";
    tree.printPreOrderIterative();
    cout<<endl;

    return 0;
}
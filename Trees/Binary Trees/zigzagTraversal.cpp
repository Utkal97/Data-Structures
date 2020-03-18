#include<bits/stdc++.h>
#include "BinaryTreeClass_int.h"

using namespace std;

void zigzagTraversal(node* root) {
    if(root==NULL)
        return;
    
    stack<node*> st1, st2;
    st1.push(root);

    while(!st1.empty() || !st2.empty()) {
        node* curr;
        while(!st1.empty()) {
            curr = st1.top();
            st1.pop();
            cout<<curr->data<<" ";

            if(curr->left)
                st2.push(curr->left);
            if(curr->right)
                st2.push(curr->right);
        }
        while(!st2.empty()) {
            curr = st2.top();
            st2.pop();
            cout<<curr->data<<" ";

            if(curr->right)
                st1.push(curr->right);
            if(curr->left)
                st1.push(curr->left);
        }
    }
    cout<<endl;
    return;
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
    tree.insertNode(10);
    tree.insertNode(11);
    tree.insertNode(12);
    tree.insertNode(13);
    tree.insertNode(14);
    tree.insertNode(15);
    tree.insertNode(16);
    tree.insertNode(17);
    tree.insertNode(18);

    cout<<"Level order : ";
    tree.printLevelOrder();
    cout<<endl;

    node* root = tree.getRoot();
    zigzagTraversal(root);
    return 0;
}
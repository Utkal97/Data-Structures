#include<bits/stdc++.h>
#include "../Binary Trees/BinaryTreeClass_int.h"

using namespace std;

bool isTreeBSTIterative(node* root) {
    if(root == NULL)
        return true;
    
    queue<int> inorder;

    stack<node*> st;
    st.push(root);
    node *curr=root;
    while(!st.empty()) {

        while(curr && curr->left) {
            st.push(curr->left);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        inorder.push(curr->data);
        if(curr->right)
            st.push(curr->right);
        curr = curr->right;
    }

    int prev = inorder.front();
    inorder.pop();
    while(!inorder.empty()) {
        int curr = inorder.front();
        inorder.pop();
        if(prev > curr) {
            cout<<"Failing at "<<prev<<" "<<curr<<endl; 
            return false;
        }
        else
            prev = curr;
    }
    return true;
}

bool isTreeBSTRecursive(node* root, int *prev) {
    if(root == NULL)
        return true;
    if(!(isTreeBSTRecursive(root->left, prev)))
        return false;
    if(root->data < *prev)
        return false;
    *prev = root->data;
    return isTreeBSTRecursive(root->right, prev);
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

    node* root = tree.getRoot();
    int prev = INT_MIN;
    
    printf("Checked recursively : ");
    if(isTreeBSTRecursive(root, &prev))
        printf("Tree is Binary Search Tree\n");
    else
        printf("Not a BST\n");
    
    printf("Checked iteratively : ");
    if(isTreeBSTIterative(root))
        printf("Tree is Binary Search Tree\n");
    else
        printf("Not a BST\n");
    return 0;
}
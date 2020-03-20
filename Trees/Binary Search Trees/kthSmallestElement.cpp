#include<bits/stdc++.h>
#include "BinarySearchTreeClass_int.h"

using namespace std;

node* kthSmallestNode(node* root, int k) {
    if(root == NULL)
        return NULL;
    
    int count = 0;
    node* ans = NULL;
    stack<node*> st;
    st.push(root);
    while(!st.empty() && count < k) {
        while(root && root->left) {
            st.push(root->left);
            root=root->left;
        }

        root = st.top();
        st.pop();
        count++;
        ans = root;

        if(root->right) {
            st.push(root->right);
        }
        root = root->right;
    }
    return ans;
}

int main() {
    BinarySearchTree tree;

    tree.insertNode(5);
    tree.insertNode(3);
    tree.insertNode(8);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(9);
    tree.insertNode(1);
	tree.printInorderRecursive();
	cout<<endl;
    int k = 8;
    node* reqd = kthSmallestNode(tree.getRoot(), k);
    cout<<k<<"th smallest element is : "<<reqd->data<<endl;

    return 0;
}

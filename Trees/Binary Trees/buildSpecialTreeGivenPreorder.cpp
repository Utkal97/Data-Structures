#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node *right;
};

node* createNode(int value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

node* buildTree(string input, int &ind) {
    if(ind >= input.length())
        return NULL;
    
    node* root;
    if(input[ind]-48 == 1) {
        ind+=1;
        root = createNode(1);
    }
    else if(input[ind]-48 == 2) {
        root = createNode(2);
        ind+=1;
        root->left = buildTree(input, ind);
        root->right = buildTree(input, ind);
    }
    return root;
}

void printInorder(node* root) {
    if(root == NULL)
        return;
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
 
    string input = "221122111";
    int start_index = 0;
    node* root = buildTree(input, start_index);
    cout<<"inorder : ";
    printInorder(root);
    cout<<endl;
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

struct node {
    char data;
    node* left;
    node* right;
};

node* createNode(char value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isOperand(char x) {
    if(65<=x && x<=90)
        return true;
    else if(97<=x && x<=122)
        return true;

    return false;
}

node* buildTree(string input, int &ind) {
    if(ind < 0)
        return NULL;
    
    node* root;
    char value = input[ind];
    if(isOperand(value)) {
        ind--;
        return createNode(value);
    }

    else {
        root = createNode(value);
        ind--;
        root->right = buildTree(input, ind);
        root->left = buildTree(input, ind);
    }
    return root;
}

node* buildExpressionTreeGivenPostfix(string input) {
    int start_ind = input.length()-1;
    return buildTree(input, start_ind);
}

void printInorder(node* root) {
    if(root == NULL)
        return;
    
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


void printPostOrderRecursive(node* trav) {
    if(trav == NULL)
        return;
            
    printPostOrderRecursive(trav->left);
    printPostOrderRecursive(trav->right);
    cout<<trav->data<<" ";
}

int main() {
    string input = "ABC*+D/";
    node* root = buildExpressionTreeGivenPostfix(input);

    cout<<"in order : ";
    printInorder(root);
    cout<<endl;

    cout<<"post order : ";
    printPostOrderRecursive(root);
    cout<<endl;

    return 0;
}

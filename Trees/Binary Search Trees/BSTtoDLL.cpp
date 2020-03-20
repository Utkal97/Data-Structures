#include<bits/stdc++.h>
#include "BinarySearchTreeClass_int.h"

using namespace std;

struct DLLnode {
    int data;
    DLLnode* next;
    DLLnode* prev;
};

DLLnode* createDLLnode(int value) {
    DLLnode* newNode = new DLLnode;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

DLLnode* BSTtoDLLRecursive(node *root, DLLnode *head, node* parent) {
    if(root == NULL)
        return NULL;
    
    DLLnode *newNode = createDLLnode(root->data);
    if(root->left) {
        newNode->prev = BSTtoDLLRecursive(root->left, newNode, root);
        newNode->prev->next = newNode;
    }
    if(root->right) {
        newNode->next = BSTtoDLLRecursive(root->right, newNode, root);
        newNode->next->prev = newNode;
    }
    
    if(!root->left && !root->right)
        return newNode;
    
    else {
        if(parent->left == root) {
            while(newNode->next)
                newNode = newNode->next;
        }
        else if(parent->right == root) {
            while(newNode->prev)
                newNode = newNode->prev;
        }
        return newNode;
    }
}

DLLnode* BSTtoDLL(node* root) {
    if(root == NULL)
        return NULL;
    
    DLLnode *head = createDLLnode(-1);
    node* dummyNode = new node;
    dummyNode->data = -1;
    dummyNode->left = NULL;
    dummyNode->right = root;
    DLLnode *nextHead = BSTtoDLLRecursive(root, head, dummyNode);

    while(nextHead->prev)
        nextHead = nextHead->prev;
    
    return nextHead;
}

void printDLL(DLLnode* head) {
    cout<<"Doubly Linked List : ";
    while(head) {
        cout<<head->data;
        head = head->next;
        if(head)
            cout<<" <=> ";
    }
    cout<<endl;
    return;
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

    node *root = tree.getRoot();
    DLLnode *head = BSTtoDLL(root);
    printDLL(head);

    return 0;
}
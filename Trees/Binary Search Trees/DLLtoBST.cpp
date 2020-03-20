#include<bits/stdc++.h>
//#include ".././Data Structures/Linked Lists/DoublyLinkedListClass.h"
#include "BinarySearchTreeClass_int.h"
#include "../.././Linked Lists/DoublyLinkedListClass.h"
using namespace std;

node* createNode(int value) {
    node* newNode = new node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int findLength(Node* head) {
    int count = 0;
    while(head) {
        head = head->next;
        count++;
    }
    cout<<"length = "<<count<<endl;
    return count;
}

node* buildTree(Node *&head, int start, int end) {
    if(start > end)
        return NULL;
    
    int mid = start+(end-start)/2;

    node* leftChild = buildTree(head, start, mid-1);
    
    node* root = createNode(head->data);
    head = head->next;
    root->left = leftChild;
    root->right = buildTree(head, mid+1, end);
    return root;
}

node* DLLtoBST(Node* head) {
    int len = findLength(head);
    node* root = buildTree(head,0,len-1);
    return root;
}

bool isTreeBST(node* root, int *prev) {
    if(root == NULL)
        return true;
    if(!(isTreeBST(root->left, prev)))
        return false;
    if(root->data < *prev)
        return false;
    *prev = root->data;
    return isTreeBST(root->right, prev);
}

int main() {
    DoublyLinkedList list;
    list.insertAtBeginning(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    list.insertAtEnd(8);
    list.printList();
    Node* head = list.getHead();
    node* root = DLLtoBST(head);

    int prev = INT_MIN;
    if(isTreeBST(root, &prev))
        cout<<"Tree is BST"<<endl;
    else
        cout<<"Not BST"<<endl;
    
    return 0;
}
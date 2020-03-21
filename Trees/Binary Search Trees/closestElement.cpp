#include<bits/stdc++.h>
#include "AVLTree_int.h"

using namespace std;

int closestElement(node* root, int value) {

    if(!root)
        return INT_MIN;

    if(root->data == value)
        return value;

    int childSol;
    if(value < root->data)
        childSol = closestElement(root->left, value);
    else if(value > root->data)
        childSol = closestElement(root->right, value);
    
    if(abs(childSol - value) < abs(root->data - value))
        return childSol;
    else
        return root->data;
}

int main() {

    AVLTree tree;

    int arr[10] = {5,3,6,7,8,9,10,4,2,1};
    
    for(int i=0;i<10;i++) {
        tree.setRoot(tree.insert(arr[i]));
    }
    node* root = tree.getRoot();
    int value = 9;
    int closest = closestElement(root, value);
    cout<<closest<<endl;
    return 0;
}
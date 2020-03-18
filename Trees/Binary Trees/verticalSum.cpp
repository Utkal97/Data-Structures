#include<bits/stdc++.h>
#include "BinaryTreeClass_int.h"

using namespace std;

void verticalSum(node* root, unordered_map<int, int> &vertsum, int ind) {
    if(root == NULL)
        return;
    
    else if(root->left == NULL && root->right == NULL) {
        vertsum[ind] += root->data;
        return;
    }
    vertsum[ind] += root->data;
    verticalSum(root->left, vertsum, ind-1);
    verticalSum(root->right, vertsum, ind+1);
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

    node* root = tree.getRoot();
    unordered_map<int, int> vertical_sum;
    verticalSum(root, vertical_sum, 0);
    for(unordered_map<int,int>::iterator it=vertical_sum.begin();
         it!=vertical_sum.end();it++) {

            cout<<"vertical sum of "<<it->first<<" : "<<it->second<<endl;
    }
    return 0;
}
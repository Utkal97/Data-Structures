#include<bits/stdc++.h>
#include "AVLTree_int.h"

using namespace std;

int countElementsInRange(node* root, int a, int b) {
    if(!root)
        return 0;
    else if(root->data < a)
        return countElementsInRange(root->right, a, b);
    else if(root->data > b)
        return countElementsInRange(root->left, a, b);
    else
        return countElementsInRange(root->left, a, b) + 1 + countElementsInRange(root->right, a, b);
}

int main() {
    AVLTree tree;
    int arr[10] = {5,3,6,7,8,9,10,4,2,1};
    node* root = NULL;
    for(int i=0;i<10;i++) {
        tree.setRoot(tree.insert(arr[i]));
    }

    root = tree.getRoot();
    int a = 2, b =7;
    int count = countElementsInRange(root,a,b);
    printf("Number of elements in range %d %d : %d\n",a,b,count);
}
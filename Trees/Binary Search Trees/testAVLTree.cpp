#include<bits/stdc++.h>
#include "AVLTree_int.h"

int main() {
    AVLTree tree;
    int arr[10] = {5,3,6,7,8,9,10,4,2,1};
    node* root = NULL;
    for(int i=0;i<10;i++) {
        tree.setRoot(tree.insert(arr[i]));
        cout<<"after inserting "<<arr[i];
        root = tree.getRoot();
        cout<<", tree height : "<<tree.height(root)<<endl;
    }

    tree.printLevelOrder();

    if(tree.isBalanced(root))
        cout<<"Tree is balanced"<<endl;
    else
        cout<<"Not balanced"<<endl;
}
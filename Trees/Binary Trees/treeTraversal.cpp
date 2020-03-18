#include<bits/stdc++.h>
#include "BinaryTreeClass_int.h"

using namespace std;

int main() {
    BinaryTree tree;

    tree.insertNode(1);
    node* Root = tree.getRoot();

    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    
    // cout<<Root->data<<endl;
    // cout<<Root->left->data<<endl;
    // cout<<Root->right->data<<endl;
    // cout<<Root->left->left->data<<endl;
    // cout<<Root->left->right->data<<endl;
    // cout<<Root->right->left->data<<endl;    
    
    cout<<"Level Order : ";
    tree.printLevelOrder();
    cout<<endl;

    cout<<"Inorder recursive : ";
    tree.printInorderRecursive(Root);
    cout<<endl;

    //incomplete
    cout<<"Inorder iterative : ";
    tree.printInorderIterative();
    cout<<endl;

    cout<<"Preorder recursive : ";
    tree.printPreOrderRecursive(Root);
    cout<<endl;
    
    //incomplete
    cout<<"Preorder iterative : ";
    tree.printPreOrderIterative();
    cout<<endl;

    cout<<"Postorder recursive : ";
    tree.printPostOrderRecursive(Root);
    cout<<endl;

    //incomplete
    cout<<"Postorder iterative : ";
    tree.printPostOrderIterative();
    cout<<endl;

    cout<<"Height of tree : "<<tree.height()<<endl;

    cout<<"Diameter of tree : "<<tree.diameter()<<endl;

    return 0;
}

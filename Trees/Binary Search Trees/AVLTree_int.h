#include<bits/stdc++.h>
#include "BinarySearchTreeClass_int.h"

using namespace std;

class AVLTree : public BinarySearchTree {
    protected:
        node* rotateLeftOnce(node* reqd) {

            node* newChild = reqd->left;
            reqd->left = newChild->right;
            newChild->right = reqd;
            return newChild;
        }

        node* rotateRightOnce(node* reqd) {

            node* newChild = reqd->right;
            reqd->right = newChild->left;
            newChild->left = reqd;
            return newChild;
        }

        node* rotateLeftRight(node *reqd) {

            //Left rotation of required node's left child
            node* leftChild = reqd->left;
            node* newParent = leftChild->right;
            reqd->left = newParent;
            leftChild->right = newParent->left;
            newParent->left = leftChild;

            //Right rotation of required node
            reqd->left = newParent->right;
            newParent->right = reqd;

            return newParent;
        }

        node* rotateRightLeft(node *reqd) {

            //Right rotation of required node's right child
            node* rightChild = reqd->right;
            node* newParent = rightChild->left;
            reqd->right = newParent;
            rightChild->left = newParent->right;
            newParent->right = rightChild;

            //Left rotation of required node
            reqd->right = newParent->left;
            newParent->left = reqd;

            return newParent;
        }

        node* findParent(node* reqd) {
            node *parent = NULL, *curr = root;
            while(curr) {
                if(reqd->data == curr->data) {
                    break;
                }
                else if(reqd->data < curr->data) {
                    parent = curr;
                    curr = curr->left;
                }
                else if(reqd->data > curr->data) {
                    parent = curr;
                    curr = curr->right;
                }
            }
            return parent;
        }

    public:
        
        int height(node *curr) {
            if(!curr)
                return 0;
            else if(!curr->left && !curr->right)
                return 1;
            
            return max(height(curr->left), height(curr->right))+1;
        }

        node* insertNode(node* curr, int value) {
            if(curr == NULL)
                curr = createNode(value);
    
            else if(value < curr->data) {
                curr->left = insertNode(curr->left, value);

                if(height(curr->left) - height(curr->right) >= 2){
                    if(value < curr->left->data)
                        curr = rotateLeftOnce(curr);
                    else
                        curr = rotateLeftRight(curr);
                }
            }
            else if(value > curr->data) {
                curr->right = insertNode(curr->right, value);

                if(height(curr->right) - height(curr->left) >= 2) {
                    if(value > curr->right->data)
                        curr = rotateRightOnce(curr);
                    else
                        curr = rotateRightLeft(curr);
                }
            }
            return curr;
        }

        node* insert(int value) {
            root = insertNode(root, value);
            return root;
        }

        bool isBalanced(node *curr) {
            if(!curr)
                return true;
            
            if(abs(height(curr->left) - height(curr->right)) <= 1)
                return isBalanced(curr->left) && isBalanced(curr->right);
            else
                return false;
        }
};
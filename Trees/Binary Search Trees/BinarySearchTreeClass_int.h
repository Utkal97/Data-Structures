#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class BinarySearchTree {
    private:
        node* createNode(int value) {
            node* newNode = new node;

            if(!newNode) {
                printf("Memory Error!");
                return NULL;
            }
            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;

            return newNode;
        }

        node* root = NULL;

        node* addNode(node* trav, node* newNode) {
            if(!trav)
                return newNode;

            if(newNode->data < trav->data)
                trav->left = addNode(trav->left, newNode);
            else if(newNode->data > trav->data)
                trav->right = addNode(trav->right, newNode);
            return trav;
        }
        
        node* findValue(node* trav, int value) {
            if(trav == NULL)
                return NULL;
            while(trav) {
                if(trav->data == value)
                    return trav;
                else if(value < trav->data)
                    trav = trav->left;
                else
                    trav = trav->right;
            }
            return NULL;
        }

        void inOrderRecursive(node* trav) {
            if(!trav)
                return;
            
            inOrderRecursive(trav->left);
            cout<<trav->data<<" ";
            inOrderRecursive(trav->right);
        }

        void preOrderRecursive(node* trav) {
            if(!trav)
                return;

            cout<<trav->data<<" ";
            preOrderRecursive(trav->left);
            preOrderRecursive(trav->right);
        }

        void postOrderRecursive(node* trav) {
            if(!trav)
                return;

            postOrderRecursive(trav->left);
            postOrderRecursive(trav->right);
            cout<<trav->data<<" ";
        }

    public:

        void insertNode(int value) {
            node* newNode = createNode(value);
            if(root == NULL)
                root = newNode;
            else
                newNode = addNode(root, newNode);
            return;
        }

        node* findNode(int value) {
            if(root == NULL)
                return NULL;
            return findValue(root, value);
        }

        void deleteNode(int value) {
            node *reqd = root, *parent = NULL;
            bool reqd_is_left_child = true;

            while(reqd) {
                if(reqd->data == value)
                    break;
                else if(value < reqd->data) {
                    parent = reqd;
                    reqd = reqd->left;
                    reqd_is_left_child = true;
                }
                else {
                    parent = reqd;
                    reqd = reqd->right;
                    reqd_is_left_child = false;
                }
            }

            if(!reqd) {
                cout<<"No node found with value : "<<value<<endl;
                return;
            }

            node* replacement;

            //node to be deleted has only one child
            if(reqd->left && !reqd->right) {
                replacement = reqd->left;
                if(reqd_is_left_child)
                    parent->left = replacement;
                else
                    parent->right = replacement;
            }
            else if(!reqd->left && reqd->right) {
                replacement = reqd->right;
                if(reqd_is_left_child)
                    parent->left = replacement;
                else
                    parent->right = replacement;
            }
            //node to be deleted is a leaf
            else if(!reqd->left && !reqd->right) {
                if(reqd_is_left_child)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            }
            //node to be deleted has two children
            else {
                replacement = inorderPredecessor(reqd);

                //attach the children of node to the replacement sub tree
                node* leftmost_node = replacement;
                while(leftmost_node->left)
                    leftmost_node = leftmost_node->left;
                
                leftmost_node->left = reqd->left;

                node* rightmost_node = replacement;
                while(rightmost_node->right)
                    rightmost_node = rightmost_node->right;

                rightmost_node->right = reqd->right;

                node* replacement_parent = reqd->left;
                while(replacement_parent->right != replacement)
                    replacement_parent = replacement_parent->right;

                replacement_parent->right = NULL;

                if(reqd_is_left_child)
                    parent->left = replacement;
                else
                    parent->right = replacement;
            }

            free(reqd);

            return;
        }

        node* inorderPredecessor(node* reqd) {
            if(!reqd->left)
                return NULL;
            
            reqd = reqd->left;
            while(reqd->right)
                reqd = reqd->right;
            return reqd;
        }

        node* inorderSuccessor(node* reqd) {
            if(!reqd->right)
                return NULL;
            
            reqd = reqd->right;
            while(reqd->left)
                reqd = reqd->left;
            return reqd;
        }

        void printInorderRecursive() {
            cout<<"In order : ";
            inOrderRecursive(root);
            cout<<endl;
            return;
        }

        void printPreOrderRecursive() {
            cout<<"Pre Order : ";
            preOrderRecursive(root);
            cout<<endl;
            return;
        }

        void printPostOrderRecursive() {
            cout<<"Post Order : ";
            postOrderRecursive(root);
            cout<<endl;
            return;
        }

        void printLevelOrder() {
            cout<<"Level Order : ";
            if(!root)
                return;
            
            queue<node*> q;
            q.push(root);
            node* curr;
            while(!q.empty()) {
                curr = q.front();
                q.pop();

                cout<<curr->data<<" ";

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            cout<<endl;
            return;
        }

        node* minNode() {
            node* minNode = root;
            while(minNode->left) {
                minNode = minNode->left;
            }
            return minNode;
        }

        node* maxNode() {
            node* maxNode = root;
            while(maxNode->right) {
                maxNode = maxNode->right;
            }
            return maxNode;
        }

        node* getRoot() {
            return root;
        }

        void setRoot(node* newRoot) {
            root = newRoot;
            return;
        }
};
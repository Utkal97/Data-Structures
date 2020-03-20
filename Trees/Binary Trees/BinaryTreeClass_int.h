#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

class BinaryTree {
    private:

        node* createNode(int value) {
            node* newNode = new node;

            if(!newNode) {
                cout<<"Memory Error";
                return NULL;
            }

            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;

            return newNode;
        }

        vector<int> findDiameterAndHeight(node* trav) {
            if(trav == NULL)
                return {0,0};
            else if(trav->left == NULL && trav->right == NULL)
                return {1,1};
            
            vector<int> left_tree = findDiameterAndHeight(trav->left);
            vector<int> right_tree = findDiameterAndHeight(trav->right);

            int curr_diameter = max(left_tree[0], right_tree[0]);
            curr_diameter = max(curr_diameter, left_tree[1] + 1 + right_tree[1]);

            int curr_height = max(left_tree[1], right_tree[1]) + 1;

            return {curr_diameter, curr_height};
        }

    public:

        node* root = NULL;

        void insertNode(int value) {
            node* newNode = createNode(value);
            if(root == NULL)
                root = newNode;

            else {
                queue<node*> q;
                q.push(root);
                node* curr;
                while(!q.empty()) {
                    curr = q.front();
                    q.pop();

                    if(curr->left)
                        q.push(curr->left);
                    else {
                        curr->left = newNode;
                        return;
                    }

                    if(curr->right)
                        q.push(curr->right);
                    else {
                        curr->right = newNode;
                        return;
                    }
                }
            }
            return;
        }

        node* getRoot() {
            return root;
        }

        void setRoot(node* newRoot) {
            root = newRoot;
            return;
        }
        
        void insertAt(node* thisNode, int value) {
            thisNode = createNode(value);
            return;
        }

        void printLevelOrder() {
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

            return;
        }

        void printInorderRecursive(node* trav) {
            if(trav == NULL)
                return;
            
            printInorderRecursive(trav->left);
            cout<<trav->data<<" ";
            printInorderRecursive(trav->right);
        }

        void printInorderIterative() {
            if(root == NULL)
                return;

            stack<struct node*> st;
            st.push(root);
            struct node* curr = root;

            while(!st.empty()) {

                while(curr && curr->left) {			//Go to the farthest left node.
                    st.push(curr->left);			//keep pushing left nodes to the stack
                    curr = curr->left;
                }
                
                curr = st.top();
                cout<<curr->data<<" ";				//print the node at top of stack
                st.pop();
                
                if(curr->right) 				    //if it has right child, make the current node the right child of current
                    st.push(curr->right);			//also, push the right child to stack
                
                curr = curr->right;
            }
            return;
        }

        void printPostOrderRecursive(node* trav) {
            if(trav == NULL)
                return;
            
            printPostOrderRecursive(trav->left);
            printPostOrderRecursive(trav->right);
            cout<<trav->data<<" ";
        }

        void printPostOrderIterative() {
            printf("Incomple\n");
            return;
        }

        void printPreOrderRecursive(node* trav) {
            if(trav == NULL)
                return;

            cout<<trav->data<<" ";
            printPreOrderRecursive(trav->left);
            printPreOrderRecursive(trav->right);
        }

        void printPreOrderIterative() {
            stack<node*> st;
            node* curr = root;
            while(curr!=NULL || !st.empty()) {
                while(curr) {
                    cout<<curr->data<<" ";
                    st.push(curr);
                    curr = curr->left;
                }

                curr = st.top();
                st.pop();
                curr = curr->right;
            }

            return;
        }

        int height() {
            if(root == NULL)
                return 0;
            
            int height_of_tree = 0;
            queue<node*> q;
            q.push(root);
            
            while(!q.empty()) {

                int nodes_at_level = q.size();

                while(nodes_at_level--) {
                    node* curr = q.front();
                    q.pop();

                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                }
                height_of_tree+=1;
            }

            return height_of_tree;
        }

        void deleteTree() {
            if(root == NULL)
                return;
            
            else {
                queue<node* > q;
                q.push(root);
                node* curr;
                while(!q.empty()) {
                    curr = q.front();
                    q.pop();

                    if(curr->left)
                        q.push(curr->left);
                    if(curr->right)
                        q.push(curr->right);
                    
                    free(curr);
                }
                root = NULL;
            }
            return;
        }

        int diameter() {
            vector<int> diameter_height =  findDiameterAndHeight(root);
            return diameter_height[0];  //diameter_height is a tuple, where 0 index : diameter
                                        //                                  1 index : height
        }
};
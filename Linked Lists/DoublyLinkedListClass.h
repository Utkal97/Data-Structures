#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};

class DoublyLinkedList {

	private:

		struct Node* root = NULL;

		Node* createNode(int val) {
			Node* newNode = new Node;
			newNode->data = val;
			newNode->next = NULL;
			newNode->prev = NULL;

			return newNode;
		}

	public:

		int length() {
			int count = 0;
			Node* trav = root;

			while(trav != NULL) {
				count++;
				trav = trav->next;
			}

			return count;
		}

		void printList() {
			
			Node* trav = root;

			cout<<"List : ";

			while(trav) {
				cout<<trav->data;
				trav = trav->next;
                if(trav)
                    cout<<" <=> ";
			}

			cout<<endl;
			return;
		}

		void insertAtBeginning(int val) {
			
			if(root == NULL)
				root = createNode(val);

			else {
				Node* temp = createNode(val);
				temp->next = root;
				root->prev = temp;

				root = temp;
			}

			return;
		}

		void insertAtEnd(int val) {
			insertAtPos(length()+1, val);
			return;
		}

		void insertAtPos(int pos, int val) {

			if(pos <= 1)
				insertAtBeginning(val);

			else {

				int trav_ind = 1;
				Node* trav = root;

				while(trav != NULL && trav_ind < pos-1) {
					trav = trav->next;
					trav_ind++;
				}
				
				if(trav == NULL)
					cout<<"given position is out of bounds"<<endl;
				else {
					Node* temp = trav->next;
					Node* newNode = createNode(val);
	
					newNode->prev = trav;
					newNode->next = temp;
	
					trav->next = newNode;
	
					if(temp!=NULL)
						temp->prev = newNode;
				}
			}

			return;
		}
		
		void deleteAtBeginning() {
			Node* temp = root;

			root = root->next;
            root->prev = NULL;
            free(temp);
            root = NULL;
            return;
		}
		
		void deleteAtPos(int pos) {
			if(pos <= 1)
				deleteAtBeginning();

			else {
				int trav_ind = 1;
				Node* trav = root;

				while(trav!=NULL && trav_ind < pos-1) {
					trav_ind++;
					trav = trav->next;
				}

				Node* temp = trav->next;
				
				if(trav->next != NULL) {
					trav->next = trav->next->next;
					
					if(trav->next!=NULL) {
						trav->next->prev = trav;
					}
					
					free(temp);
				}
			}
			printList();
			return;
		}

        Node* getHead() {
            return root;
        }

        void setHead(Node* newRoot) {
            root = newRoot;
            return;
        }
};
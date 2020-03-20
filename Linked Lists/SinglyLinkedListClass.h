#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

class SinglyLinkedList 
{
	private:
		
		Node* createNode(int val) {

			Node* newNode = new Node;
			newNode->data = val;
			newNode->next = NULL;

			return newNode;
		}
		
		
	public:

		struct Node* root = NULL;

		void append(int value) {
			if(root == NULL) {
				root = createNode(value);
			}
			else {
				struct Node* trav = root;
	
				while(trav->next !=NULL)
					trav = trav->next;
	
				trav->next = createNode(value);				
			}
			printList();
			return;
		}
		
		void printList() {

			cout<<"length = "<< length() <<" Printing list : ";
			
			Node *trav = root;
			
			while(trav!=NULL) {
				cout<<trav->data<<"->";
				trav = trav->next;
			}

			cout<<"NULL"<<endl;
			
			return;
		}
		
		int length() {
			Node *trav = root;
			
			int count = 0;

			while(trav != NULL) {
				count++;
				trav = trav->next;
			}
			return count;
		}
		
		void insertAtPos(int pos, int val) {

			if(pos <= 0) {
				cout<<"given position out of bounds"<<endl;
				return;
			}
				
				
			if(pos == 1) {
				Node* newNode = createNode(val);
				
				if(root == NULL)
					root = newNode;

				else {
					newNode->next = root;
					root = newNode;
				}
				
			}
			
			else {
				int trav_ind = 1;
				Node* trav = root;
	
				while(trav != NULL && trav_ind < pos-1) {
	
					trav = trav->next;
					trav_ind++;
				}
	
				if(trav == NULL)
					cout<<" given position out of bounds"<<endl;
				else {
					Node* newNode = createNode(val);
					
					Node* temp = trav->next;
					trav->next = newNode;
					newNode->next = temp;
				}
			}
			printList();
			return;
		}
		
		void insertAtBeginning(int val) {
			insertAtPos(1, val);
		}
		
		void insertAtEnd(int val) {
			insertAtPos(length()+1, val);
		}
		
		void deleteAtPos(int pos) {
			if(pos==1) {
				deleteAtBeginning();
			}
			else {
				
				Node* trav = root;
				int trav_ind = 1;
				
				while(trav!=NULL && trav_ind<pos-1) {
					trav = trav->next;
					trav_ind++;
				}

				if(trav == NULL)
					cout<<"given position out of bounds"<<endl;

				else if(trav->next != NULL) {
					Node* temp = trav->next;

					trav->next = trav->next->next;
					free(temp);
				}
			}
			
			cout<<"Delete element at pos "<<pos;
			printList();
			return;
		}
		
		void deleteAtBeginning() {
			if(root == NULL)
				cout<<"there is no linked list";

			else {
				Node *temp = root;
				root = root->next;
				free(temp);
			}

			cout<<"delete at begining";
			deleteAtPos(1);
			return;
		}

		void deleteAtEnd() {
			cout<<"Delete at end";
			deleteAtPos(length());
			return;
		}

		void deleteList() {
			Node* trav = root;

			while(trav!=NULL) {

				Node* temp = trav;
				trav = trav->next;
				free(temp);
			}
			root = NULL;
			
			cout<<"List is deleted";
			printList();
			return;
		}
		
		void reverse() {
			if(root != NULL && root->next != NULL) {

				Node* head = root->next, *prev = NULL, *curr = root, *nextN = curr->next;

				while(curr!=NULL) {
					
					curr->next = prev;
					prev = curr;
					curr = nextN;
					if(nextN != NULL)
						nextN = nextN->next;
				}
				
				root = prev;			
			}
			cout<<"reversing the list :";
			printList();
			return;
		}
		
		void reverseInPairs() {
			if(root != NULL && root->next != NULL) {
				Node *newHead = root->next;
				Node *prev = NULL, *one = root, *two = root;
				
				while(one!=NULL && two!=NULL) {
					prev->next = two;
					Node *nextN = two->next;
					two->next = one;
					one->next = nextN;
					prev = one;
					one = nextN;
					if(nextN!=NULL)
						two = nextN->next;
					else
						break;
				}
				root = newHead;
			}
			
			cout<<"Reversed in pairs :";
			printList();
			return;
		}
};
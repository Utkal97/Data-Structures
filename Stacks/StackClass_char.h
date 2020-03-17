#include<bits/stdc++.h>
using namespace std;

struct node {
	char data;
	struct node* next;
};

class Stack {
	
	private:
		
		node* createNode(char val) {
			node* newNode = new node;
			newNode->data = val;
			newNode->next = NULL;
			return newNode;
		}
		
		node *topNode = NULL;
		int size = 0;
		
	public:

		void push(char val) {
			node* newTop = createNode(val);
			
			if(topNode == NULL)
				topNode = newTop;
			
			else {
				newTop->next = topNode;
				topNode = newTop;
			}
			return;
		}
		
		char pop() {
			char top_value;
			
			if(topNode==NULL)
				return '$'; 

			else {
				top_value = topNode->data;
				node* temp = topNode;
				topNode = topNode->next;
				free(temp);
			}
			return top_value;
		}
		
		bool isEmpty() {
			if(topNode)
				return false;
		
			return true;
		}
		
		void printStack() {
			//cout<<"Stack : ";	
			node* trav = topNode;
			
			while(trav) {
				printf("%c",trav->data);
				trav = trav->next;
				
				if(trav)
					printf(",");
			}
			cout<<endl;
			return;
		}
		
		char top() {
			if(topNode)
				return topNode->data;
			return '$';
		}
		
		void deleteStack() {
			while(topNode) {
				node* temp = topNode;
				topNode = topNode->next;
				free(temp);
			}
			return;
		}
};
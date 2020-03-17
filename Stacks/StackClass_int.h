#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node* next;
};

class Stack {
	
	private:
		
		node* createNode(int val) {
			node* newNode = new node;
			newNode->data = val;
			newNode->next = NULL;
			return newNode;
		}
		
		node *topNode = NULL;
		int size = 0;
		
	public:

		void push(int val) {
			node* newTop = createNode(val);
			
			if(topNode == NULL)
				topNode = newTop;
			
			else {
				newTop->next = topNode;
				topNode = newTop;
			}
			return;
		}
		
		int pop() {
			int top_value;
			
			if(topNode==NULL)
				return INT_MIN;

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
			node* trav = topNode;
			
			while(trav) {
				printf("%d",trav->data);
				trav = trav->next;
				
				if(trav)
					printf(",");
			}
			cout<<endl;
			return;
		}
		
		int top() {
			if(topNode)
				return topNode->data;
			return INT_MIN;
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
#include<iostream>
using namespace std;

struct node {
    int data;
    node* prev;
    node* next;
};

class DoubleEndedQueue {
    private:
        node* createNode(int value) {
            node* newNode = new node;
            newNode->data = value;
            newNode->prev = NULL;
            newNode->next = NULL;

            return newNode;
        }

        node* head = NULL;
        node* tail = NULL;

    public:
        void push_back(int value) {
            if(head == NULL) {
                head = createNode(value);
                tail = head;
            }
            else {
                node* newNode = createNode(value);
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            return;
        }

        void push_front(int value) {
            if(head == NULL) {
                head = createNode(value);
            }
            else {
                node* newNode = createNode(value);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            return;
        }

        int pop_back() {
            if(head == NULL)
                return -1;
            
            node *tailPrevNode = tail->prev, *temp = tail;
            tailPrevNode->next = NULL;

            int tailData = tail->data;
            free(temp);
            tail = tailPrevNode;
            return tailData;
        }

        int pop_front() {
            if(head == NULL)
                return -1;
            
            node *nextHead = head->next, *temp = head;
            nextHead->prev = NULL;

            int headData = head->data;
            free(temp);
            head = nextHead;
            return headData;
        }

        void printQueue() {
            node* trav = head;
            while(trav) {
                cout<<trav->data;
                trav = trav->next;
                if(trav)
                    cout<<",";
            }
            cout<<endl;
            return;
        }
};
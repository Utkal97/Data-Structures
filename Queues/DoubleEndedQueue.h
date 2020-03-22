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
        int size = 0;

    public:
        void push_back(int value) {
            if(empty()) {
                head = createNode(value);
                tail = head;
            }
            else {
                node* newNode = createNode(value);
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            size++;
            //cout<<"push back "<<value<<endl;
            return;
        }

        void push_front(int value) {
            if(empty()) {
                head = createNode(value);
                tail = head;
            }
            else {
                node* newNode = createNode(value);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            size++;
            //cout<<"push front "<<value<<endl;
            return;
        }

        int pop_back() {
            if(empty())
                return -1;
            
            node *tailPrevNode = tail->prev, *temp = tail;
            if(tailPrevNode)
                tailPrevNode->next = NULL;

            int tailData = tail->data;
            free(temp);
            size--;
            if(size==0)
                head = NULL;

            tail = tailPrevNode;

            //cout<<"pop back "<<endl;
            return tailData;
        }

        int pop_front() {
            if(head == NULL)
                return -1;
            
            node *nextHead = head->next, *temp = head;
            nextHead->prev = NULL;

            int headData = head->data;
            free(temp);
            size--;
            head = nextHead;
            //cout<<"pop front "<<endl;
            return headData;
        }

        int front() {
            return head->data;
        }

        int back() {
            return tail->data;
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

        bool empty() {
            return head==NULL;
        }
};
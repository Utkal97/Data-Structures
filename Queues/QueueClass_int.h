#include<iostream>
using namespace std;

struct node {
    int data;
    struct node* next;
};

class Queue {

    private:
        node* createNode(int value) {
            node* newNode = new node;
            newNode->data = value;
            newNode->next = NULL;
            return newNode;
        }

        node* head = NULL;
        node* tail = head;
        int queue_size = 0;
    
    public:
        void push(int value) {
            node* newNode = createNode(value);

            if(head == NULL) {
                head = newNode;
                tail = head;
            }
            else {
                tail->next = newNode;
                tail = tail->next;
            }
            queue_size++;
            return;
        }

        int pop() {
            if(!empty()) {
                int head_value = head->data;

                node* temp = head;
                head = head->next;
                free(temp);
                queue_size--;
                return head_value;
            }

            else
                return -1;            
        }

        int front() {
            if(head)
                return head->data;
            else
                return 0;            
        }

        bool empty() {
            return head == NULL;            
        }

        int size() {
            return queue_size;
        }

        void printQueue() {

            node* trav = head;

            while(trav) {
                printf(" %d", trav->data);
                trav = trav->next;
                if(trav)
                    printf(",");
            }
            return;
        }
};
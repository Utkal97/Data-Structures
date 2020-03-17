#include<bits/stdc++.h>
#include "StackClass_int.h"
using namespace std;

class QueueWithStacks {
    private:
        Stack st1, st2;
        bool stack1_holds_content = 1;
    public:
        void push(int value) {
            
            while(!st2.isEmpty()) {
                st1.push(st2.pop());
            }
            stack1_holds_content = true;
            st1.push(value);
            return;
        }

        int pop() {
            while(!st1.isEmpty()) {
                st2.push(st1.pop());
            }
            stack1_holds_content = false;
            
            return st2.pop();
        }

        void printQueue() {
            if(stack1_holds_content) {
                cout<<"stack 1 contains : ";
                st1.printStack();
            }
            else {
                cout<<"stack 2 contains : ";
                st2.printStack();
            }   
            return;
        }
};

int main() {
    QueueWithStacks q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    q.push(6);
    cout<<q.pop()<<endl;
    q.push(7);
    cout<<q.pop()<<endl;
    return 0;
}
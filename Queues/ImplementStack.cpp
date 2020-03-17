#include<bits/stdc++.h>
#include "QueueClass_int.h"
using namespace std;

class StackWithQueues {
    private:
        Queue q1, q2;
        bool queue1_holds_content = true;

    public:
        void push(int value) {
            if(queue1_holds_content)
                q1.push(value);
            else
                q2.push(value);
            return;
        }

        int pop() {
            if(queue1_holds_content) {
                while(q1.size() > 1) {
                    q2.push(q1.pop());
                }
                queue1_holds_content = false;
                
                if(!q1.empty())
                    return q1.pop();
                else
                    return -1;
            }
            else {
                while(q2.size() > 1) {
                    q1.push(q2.pop());
                }
                queue1_holds_content = true;
                if(!q2.empty())
                    return q2.pop();
                else
                    return -1;
            }
        }

        void printQueue() {
            cout<<"stack :";
            if(queue1_holds_content)
                q1.printQueue();
            else
                q2.printQueue();            
        }
};

int main() {
    StackWithQueues st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout<<"popped : "<<st.pop()<<endl;

    st.push(4);
    st.push(5);

    cout<<"popped : "<<st.pop()<<endl;
    st.printQueue();

    return 0;
}
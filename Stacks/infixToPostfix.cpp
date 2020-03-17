#include "StackClass_char.h"
#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
    char symbols[5] = {'+','-','*','/','^'};
    for(int i=0; i<5; i++) {
        if(ch == symbols[i])
            return true;
    }
    return false;
}

int precedence(char op) {
    if(op == '^')
        return 3;
    else if(op == '*' || op == '/')
        return 2;
    else if(op=='+' || op=='-')
        return 1;
    return 0;
}

string reverseString(string postfix) {
    int len = postfix.length();
    int mid = len/2;
    for(int i=0, j=len-1; i<=mid && j>=mid; i++, j--) {
        char temp = postfix[i];
        postfix[i] = postfix[j];
        postfix[j] = temp;
    }
    return postfix;
}

string infixToPostfix(string s) {

    Stack output_stack;
    Stack operator_stack;

    for(int i=0; i<s.length(); i++) {

        if(isOperator(s[i])) {
            if(operator_stack.isEmpty() || operator_stack.top()=='(')
                operator_stack.push(s[i]);

            else {
                while( !operator_stack.isEmpty() &&
                   precedence(s[i]) <= precedence(operator_stack.top()) ) {
                       
                       char top = operator_stack.top();
                       output_stack.push(top);
                       operator_stack.pop();
                }

                operator_stack.push(s[i]);                
            }
        }

        else if(s[i] == '(')
            operator_stack.push(s[i]);

        else if(s[i] == ')') {
            while( !operator_stack.isEmpty() && 
               operator_stack.top()!='(' ) {

                char top = operator_stack.top();
                output_stack.push(top);
                operator_stack.pop();
            }

            if(operator_stack.top()=='(')
                operator_stack.pop();
        }

        else
            output_stack.push(s[i]);
    }

    while(!operator_stack.isEmpty()) {

        char top = operator_stack.top();
        output_stack.push(top);
        operator_stack.pop();
    }

    string postfix = "";
    while(!output_stack.isEmpty()) {

        char top =output_stack.top();
        postfix.push_back(top); 
        output_stack.pop();
    }

    postfix = reverseString(postfix);
    return postfix;
}

int main() {
	string s ="a+b*(c^d-e)^(f+g*h)-i";
    cout<<"Infix : "<<s<<endl;
    string output_s = infixToPostfix(s);
    cout<<"Postfix : "<<output_s<<endl;
	return 0;
}

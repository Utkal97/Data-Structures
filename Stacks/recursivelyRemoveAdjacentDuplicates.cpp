#include<bits/stdc++.h>
#include "StackClass_char.h"
using namespace std;

string reverseString(string input) {
    int len = input.length();
    int mid = len/2;
    for(int i=0, j=len-1; i<=mid, j>=mid; i++, j--) {
        char temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    return input;
}

string removeAdjacentDuplicates(string s) {

    Stack st;
    int len = s.length();
    for(int i=0; i<len;) {

        if(st.isEmpty())
            st.push(s[i]);
        
        else {
            if(s[i] == st.top()) {
                while(s[i] == st.top()) {
                    i++;
                }
                
                st.pop();
                i--;
            }
            else
                st.push(s[i]);
        }
        i++;
    }

    string output;

    while(!st.isEmpty()) {
        output.push_back(st.top());
        st.pop();
    }

    output = reverseString(output);
    return output;
}

int main()
 {
	int T= 1;
//	scanf("%d",&T);
    //while(T--) {
        string input = "caaabbbaacdddd";
        //cin>>inp;
        string output = removeAdjacentDuplicates(input);
        cout<<output<<endl;
	//}
	return 0;
}
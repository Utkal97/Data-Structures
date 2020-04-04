#include<bits/stdc++.h>

using namespace std;

//args : (string input1, string input2, int inp_ind, int patt_ind).
int longestCommonSubsequenceLength(string input1, string input2, int inp_ind, int patt_ind) {
    if(inp_ind >= input1.size() || patt_ind >= input2.size())
        return 0;

    if(input1[inp_ind] == input2[patt_ind])
        return 1+longestCommonSubsequenceLength(input1, input2, inp_ind+1, patt_ind+1);

    else
        return max(longestCommonSubsequenceLength(input1, input2, inp_ind+1, patt_ind),
            longestCommonSubsequenceLength(input1, input2, inp_ind, patt_ind+1));
}

int main() {
    string input1 = "ABCBDAB", input2 = "BDCABA";
    int len = longestCommonSubsequenceLength(input1, input2,0,0);
    cout<<len<<endl;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

int max(int x, int y) {
    return x>y ? x : y;
}

//args : (string input1, string input2, int inp1_ind, int inp2_ind). Run time : O(N*M)
int longestCommonSubsequence(string input1, string input2) {

    int len1 = input1.size(), len2 = input2.size();

    int LCS[len1+1][len2+1];

    for(int i=0;i<=len1;i++) {
        for(int j=0;j<=len2;j++) {
            LCS[i][j] = 0;
        }
    }

    for(int i=len1-1; i>=0; i--) {
        for(int j=len2-1; j>=0; j--) {
            if(input1[i] == input2[j])
                LCS[i][j] = LCS[i+1][j+1]+1;
            else
                LCS[i][j] = max(LCS[i][j+1], LCS[i+1][j]);
        }
    }

    for(int i=0;i<=len1;i++) {
        for(int j=0;j<=len2;j++) {
            printf("%d ",LCS[i][j]);
        }
        cout<<endl;
    }

    //printing LCS
    cout<<"longest common subsequence : ";
    int i=0, j=0;
    while(i<len1 && j<len2) {
        if(input1[i] == input2[j]) {
            cout<<input1[i];
            i++,j++;
        }
        else {
            if(LCS[i][j+1]>LCS[i+1][j]) {
                while(j<len2 && LCS[i][j+1] == LCS[i][j])
                    j++;
                if(j==len2)
                    break;
                cout<<input2[j];
                j++;
            }
            else {
                while(i<len1 && LCS[i+1][j] == LCS[i][j])
                    i++;
                if(i==len1)
                    break;
                cout<<input1[i];
                i++;
            }
        }
    }
    cout<<endl;

    return LCS[0][0];
}

int main() {
    string input1 = "ABCBDAB", input2 = "BB";
    int len = longestCommonSubsequence(input1, input2);
    cout<<"length of longest common subsequence : "<<len<<endl;
    return 0;
}

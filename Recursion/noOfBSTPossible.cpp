#include<bits/stdc++.h>
using namespace std;

int CatalanNumber(int n) {
    if(n<0)
        return 0;
    else if(n==0 || n==1)       //even 0 nodes makes a tree
        return 1;

    int total = 0;
    for(int i=1;i<=n;i++) {
        total += CatalanNumber(i-1) * CatalanNumber(n-i);
    }
    return total;
}
int main() {
    int n = 5;
    int no_of_BST_possible = CatalanNumber(n);
    cout<<"Number of BSTs possible : "<<no_of_BST_possible<<endl;
    return 0;
}
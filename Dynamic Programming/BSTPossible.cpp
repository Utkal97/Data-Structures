#include<bits/stdc++.h>
using namespace std;

//input : (int nodes). Computes number of BSTs possible to construct.
int CatalanNumber(int n) {
    if(n<0)
        return 0;

    else if(n==0 || n==1)
        return 1;

    //DP array that contains Catalan Number of given nodes
    int cat[n+1] = {0};

    cat[0] = 1;
    cat[1] = 1;

    for(int nodes=2;nodes<=n;nodes++) {
        for(int i=1; i<=nodes; i++) {
            cat[nodes] += cat[i-1]*cat[nodes-i];
        }
        printf("for %d nodes : %d\n",nodes, cat[nodes]);
    }
    return cat[n];
}

int main() {
    int n = 5;
    int no_of_BST_possible = CatalanNumber(n);
    cout<<no_of_BST_possible<<endl;

    return 0;
}
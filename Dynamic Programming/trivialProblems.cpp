#include<bits/stdc++.h>
using namespace std;

//convert recurrence relation into DP (prob. 1)
int f(int n) {
    int f0 = 2, f1 = 2;

    int result = 0;
    for(int i=1; i<=n-1; i++) {
        int current_term = 2*f1*f0;
        result += current_term;
        f0 = f1;
        f1 = current_term;
    }
    return result;
}

int main() {
    int n = 5, k = f(n);
    cout<<k<<endl;
    return 0;
}
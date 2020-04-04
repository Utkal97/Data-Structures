#include<bits/stdc++.h>

using namespace std;

int max(int x, int y) {
    return x>y ? x : y;
}

int maxContiguousSumSubsequence(int array[], int len) {
    
    //DP array for memoization
    int contiguousSumArray[len] = {0};

    contiguousSumArray[0] = array[0];
    for(int i=1; i<len; i++) {

        //either choose to add on to previous sum OR start a new subsequence.
        contiguousSumArray[i] = max(array[i], contiguousSumArray[i-1] + array[i]);
    }
    
    int maxSum = contiguousSumArray[0];
    for(int i=1; i<len; i++) {
        if(maxSum < contiguousSumArray[i])
            maxSum = contiguousSumArray[i];
    }
    return maxSum;
}

int main() {
    int array[6] = {-2,11,-4,13,-5,2};

    //we have to calculate length in calling function only, 
    // because array when passed to function will pass a pointer to array
    int len = sizeof(array)/sizeof(int);
    int maxSum = maxContiguousSumSubsequence(array, len);
    cout<<maxSum<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int max(int x, int y) {
    return x>y ? x : y;
}

//finds minimum value of given 3 integers
int min3(int x, int y, int z) {
    int min = x;
    if(min > y)
        min = y;
    if(min > z)
        min = z;
    return min;
}

int maxNonContiguousSumSubsequence(int array[], int len) {
    if(len == 0)
        return 0;
    else if(len == 1)
        return 1;

    //dp array contains optimal solution so far
    int sumArray[len];

    //tells if the element exists in solution
    int exists[len] = {0};

    sumArray[0] = max(0, array[0]);
    sumArray[1] = max(sumArray[0], array[1]);

    if(sumArray[1] > sumArray[2]) {
        exists[1] = 1;
        exists[0] = 0;
    }
    else if(sumArray[0]>0) {
        exists[0] = 1;
        exists[1] = 0;
    }

    for(int ind=2; ind<len; ind++) {
        if(exists[ind-1]==1 && array[ind]>0) {
            int currTermIncluded = sumArray[ind-2]+array[ind];
            if(currTermIncluded > sumArray[ind-1]) {
                exists[ind-1] = 0;
                exists[ind] = 1;
                sumArray[ind] = currTermIncluded;
            }
            else
                sumArray[ind] = sumArray[ind-1];
        }
        else if(array[ind]>0) {
            sumArray[ind] = sumArray[ind-1] + array[ind];
            exists[ind] = 1;
        }
        else {
            sumArray[ind] = sumArray[ind-1];
            exists[ind] = 0;
        }
    }

    //print elements of solutions
    cout<<"Max sum of non contiguous subsequence : ";
    for(int i=0;i<len;i++) {
        if(exists[i])
            cout<<array[i]<<" ";
    }
    cout<<endl;
    return sumArray[len-1];
}

//Max contiguous sum of sub sequence such that no 3 elements must be consecutive
int No3Consecutive(int A[], int len) {
    if(len < 3 )
        return 0;
    
    int S[len];
    int exists[len] = {0};

    S[0] = A[0];
    if(A[0] > 0)
        exists[0] = 1;

    S[1] = max(S[0]+A[1],A[1]);
    if(A[1] > 0)
        exists[1] = 1;
    for(int i=2;i<len;i++) {
        if(A[i] > 0) {
            if(exists[i-1] && exists[i-2]) {

                int min_of_3 = min3(A[i-2], A[i-1], A[i]);

                if(min_of_3 == A[i])
                    S[i] = S[i-1];

                else if(min_of_3 == A[i-1]) {
                    S[i] = S[i-2] + A[i];
                    exists[i-1] = 0;
                    exists[i] = 1;
                }
                else {
                    if(i==2)
                        S[i] = max(A[i], A[i] + A[i-1]);
                    else
                        S[i] = S[i-3] + A[i-1] + A[i];
                    exists[i-2] = 0;
                    exists[i] = 1;
                }
            }
            else {
                S[i] = max(S[i-1] + A[i],A[i]);
                exists[i] = 1;
            }
        }
        else
            S[i] = S[i-1];
    }

    //printing elements in the solutions
    cout<<"Max sum of contiguous subsequence with no 3 consecutive : ";
    for(int i=0;i<len;i++) {
        if(exists[i])
            cout<<A[i]<<" ";
    }
    cout<<endl<<"answer : ";
    return S[len-1];
}

int main() {
    int array[12] = {-7,-3,2,3,1,5,1,-6,8,-7,1,9};

    //we have to calculate length in calling function itself, 
    // because, array when passed to function will pass a pointer to array
    int len = sizeof(array)/sizeof(int);

    int maxSum = maxNonContiguousSumSubsequence(array, len);
    cout<<maxSum<<endl;
    int prob11 = No3Consecutive(array, len);
    cout<<prob11<<endl;
    return 0;
}
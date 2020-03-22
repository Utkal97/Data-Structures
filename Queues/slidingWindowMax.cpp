#include<bits/stdc++.h>
#include "DoubleEndedQueue.h"

using namespace std;

vector<int> slidingWindow(int A[], int len, int window_size) {
    DoubleEndedQueue q;
    for(int ind=0;ind<window_size;ind++) {
        while(!q.empty() && A[ind] >= A[q.back()])
            int popped = q.pop_back();

        q.push_back(ind);
    }

    vector<int> answer;
    answer.push_back(A[q.front()]);

    for(int ind=window_size; ind<len; ind++) {
        while(!q.empty() && ind-q.front() >= window_size)
            q.pop_front();

        while(!q.empty() && A[ind]>=A[q.back()])
            q.pop_back();

        q.push_back(ind);
        answer.push_back(A[q.front()]);
    }

    return answer;
}

int main() {
    int input[8] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> ans = slidingWindow(input, 8, k);

    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
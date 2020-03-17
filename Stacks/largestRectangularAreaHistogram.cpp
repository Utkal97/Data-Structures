#include<bits/stdc++.h>
#include "StackClass_char.h"

using namespace std;

int largestArea(int hist[], int n) {

    Stack st;
    int lastPositive = 0;

    int max_area = 0, curr_max = 0;

    for(int i=0; i<n; i++) {
        if(hist[i] == 0)
            while(!st.isEmpty())
                st.pop();

        else if(hist[i] > 0) {

            if(st.isEmpty())
                lastPositive = i;

            if(hist[i] > hist[st.top()])
                st.push(i);
        
            else {
                while(!st.isEmpty()) {
                    st.pop();
                }
                st.push(i);
            }

            curr_max = hist[i];






        }
    }
    return max_area;
}

int main() {

    int histogram[11] = {2,1,3,0,4,5,4,1,5,6,7};
    int max_area = largestArea(histogram, 11);
    cout<<max_area<<endl;
    return 0;
}
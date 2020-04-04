#include<bits/stdc++.h>
using namespace std;

struct matter {
    int weight;
    int value;
};

int max(int x, int y) {
    return x>y ? x:y;
}

//input : (vector<struct matter> element, int capacity). Run time : O(N*capacity)
int integerKnapsack(vector<struct matter> element, int capacity) {
    if(capacity<=0)
        return 0;

    //DP array that contains that value with current load.
    int knapsack[capacity+1] = {0};

    for(int i=0;i<=capacity;i++) {

        //selects the best element that can be chosen currently
        int maxCurr = 0;
        for(int ind = 0; ind<element.size(); ind++) {
            int item_weight = element[ind].weight;
            int item_value = element[ind].value;

            if( i>=item_weight &&  maxCurr<knapsack[i-item_weight] + item_value)
                maxCurr = knapsack[i-item_weight] + item_value;
        }

        knapsack[i] = max(knapsack[i], maxCurr);
    }    

    for(int i=0;i<=capacity;i++) {
        printf("knapsack[%d] : value : %d\n",i,knapsack[i]);
    }
    return knapsack[capacity];
}

int main() {
    int n = 4;
    vector<struct matter> element;

    int value[n] = {40,50,10,70};
    int weight[n] = {3,4,2,5};
    int capacity = 8;

    for(int i=0;i<n;i++) {
        element.push_back({weight[i], value[i]});
    }

    cout<<"given elements :- "<<endl;
    for(int i=0;i<n;i++) {
        cout<<element[i].value<<" "<<element[i].weight<<endl;
    }
    int gainedWealth = integerKnapsack(element, capacity);
    cout<<"material taken is worth : "<<gainedWealth<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int max(int x, int y) {
    return x>y ? x : y;
}

struct matter {
    int weight;
    int value;
};

int Knapsack01(vector<struct matter> element, int capacity) {
    if(capacity<=0)
        return 0;
    
    int len = element.size();
    int exists[len] = {0};

    int knapsack[capacity+1] = {0};
    int currLoad = 0;
    for(int load=1;load<capacity; load++) {
        int maxCurr = 0;
        int chosen_item = INT_MIN;
        for(int i=0;i<len;i++) {
            
        }
        if(chosen_item >= 0)
            exists[chosen_item] = 1;

        currLoad += element[chosen_item].weight;
        knapsack[load] = max(knapsack[load-1], maxCurr);
    }

    for(int i=0;i<=capacity;i++) {
        printf("knapsack[%d] : value : %d\n",i,knapsack[i]);
    }
    return knapsack[capacity];
}

int main() {
    int n = 3;
    vector<struct matter> element;

    int value[n] = {60,100,120};
    int weight[n] = {10,20,30};
    int capacity = 50;

    for(int i=0;i<n;i++) {
        element.push_back({weight[i], value[i]});
    }

    cout<<"given elements :- "<<endl;
    for(int i=0;i<n;i++) {
        cout<<element[i].value<<" "<<element[i].weight<<endl;
    }
    int gainedWealth = Knapsack01(element, capacity);
    cout<<"material taken is worth : "<<gainedWealth<<endl;
    return 0;
}
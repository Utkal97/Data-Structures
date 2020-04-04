#include<bits/stdc++.h>
using namespace std;

struct matter {
    int weight;
    int value;
};

int integerKnapsack(vector<struct matter> element, 
                int weight_left, int prev_wealth, int prev_weight) {

    if(weight_left <= 0)
        return prev_wealth;

    int chosen_value = 0, chosen_weight = 0;
    int  len = element.size();
    
    //max worth of material may be in float
    int maxCurr = 0;

    //boolean: checks if there is any material that fits in weight left.
    bool chosen_something = false;

    for(int i=0; i<len; i++) {
        int curr_val = element[i].value;
        int curr_weight = element[i].weight;

        int curr_worth = integerKnapsack(element, weight_left-curr_weight, prev_wealth+curr_val, prev_weight+curr_weight);
        if( weight_left >= curr_weight && maxCurr < curr_worth ) {
            maxCurr = curr_worth;
            chosen_weight = curr_weight;
            chosen_something = true;
        }
    }

    //if no item fits in remaining weight, we can return
    if(!chosen_something) {
        cout<<"Haven't chosen anything, weight left : "<<weight_left<<endl;
        return prev_wealth;
    }

    prev_wealth = maxCurr;
    weight_left -= chosen_weight;
    cout<<"We have chosen : "<<chosen_value<<" remaining weight : "<<weight_left<<endl;

    return prev_wealth;
}

int main() {
    int n = 4;
    vector<struct matter> element;

    int value[n] = {40,50,10,70};
    int weight[n] = {3,4,2,5};
    int weight_left = 8;

    for(int i=0;i<n;i++) {
        element.push_back({weight[i], value[i]});
    }

    cout<<"elements :- "<<endl;
    for(int i=0;i<n;i++) {
        cout<<element[i].value<<" "<<element[i].weight<<endl;
    }
    int gainedWealth = integerKnapsack(element, weight_left, 0, 0);
    cout<<"material taken is worth : "<<gainedWealth<<endl;
    return 0;
}
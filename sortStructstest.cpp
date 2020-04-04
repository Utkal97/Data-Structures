#include<bits/stdc++.h>
using namespace std;

struct matter {
    int weight;
    int value;
};

//compares two elements based on their value per unit weight.
bool compareByWorth(const matter& a, const matter& b)
{
    if(a.weight == b.weight)
        return a.value > b.value;
    else if(a.value == b.value)
        return a.weight < b.weight;

    return (float)a.value/a.weight > (float)b.value/b.weight;
}

int main() {
    
    vector<struct matter> element;
    element.push_back({11,2});
    element.push_back({20,5});

    sort(element.begin(), element.end(), compareByWorth);
    cout<<"sorted vector of structs in descending order of their value per unit weight -"<<endl;
    for(int i=0;i<element.size();i++) {
        cout<<element[i].value<<" "<<element[i].weight<<endl;
    }
    return 0;
}
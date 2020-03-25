#include<bits/stdc++.h>
using namespace std;

struct edge {
    int weight;
    int src;
    int dest;

    bool operator <(const edge& e) const {
        if(weight == e.weight) {
            if(src == e.src)
                return dest < e.dest;
            return src < e.src;
        }
        return weight < e.weight;
    }
};

edge* createEdge(int weight, int a, int b) {
    edge *newEdge = new edge;
    newEdge->weight = weight;
    newEdge->src = a;
    newEdge->dest = b;

    return newEdge;
}


int main (){ 
    set<pair<int, int> > st;

    st.insert(make_pair(1,5));
    st.insert(make_pair(3,6));
    st.insert(make_pair(2,7));

    //if pairs are used in set, ordering is based on first property of pair
    for(set<pair<int, int> > :: iterator it= st.begin(); it!=st.end(); it++) {
        printf("%d : %d\n",it->first, it->second);
    }

    if(-1)
        printf("If condition also passes negative numbers\n");
    else
        printf("If condition doesn't pass negative numbers\n");
    
    set<struct edge> s;
    s.insert({5,1,2});
    s.insert({3,2,3});
    s.insert({7,6,2});
    s.insert({7,4,3});
    
    //if structs are used in set, ordering is based on first property of pair
    for(set<struct edge> :: iterator it= s.begin(); it!=s.end(); it++) {
        printf("%d : %d %d\n",it->weight, it->src, it->dest);
    }


    return 0;
}
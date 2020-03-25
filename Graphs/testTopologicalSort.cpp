#include "DirectedGraph_AdjMatrix.h"
#include "DirectedGraph_AdjList.h"
#include<bits/stdc++.h>
using namespace std;

int main() {
    int V=8,E=0;
    DirectedGraph_AdjMatrix G(V,E);

    int a[V][V];
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            a[i][j] = 0;
        }
    }

    G.initializeGraph((int *)a);    //must type cast to int pointer while passing

    G.addEdge(2,4);
    G.addEdge(2,8);
    G.addEdge(3,7);
    G.addEdge(4,5);
    G.addEdge(6,4);
    G.addEdge(6,7);
    G.addEdge(7,1);
    G.addEdge(7,5);
    G.addEdge(7,8);

    G.topologicalSort();

    DirectedGraph_AdjList DL(V,E);

    DL.addEdge(2,4);
    DL.addEdge(2,8);
    DL.addEdge(3,7);
    DL.addEdge(4,5);
    DL.addEdge(6,4);
    DL.addEdge(6,7);
    DL.addEdge(7,1);
    DL.addEdge(7,5);
    DL.addEdge(7,8);

    DL.topologicalSort();
    return 0;
}
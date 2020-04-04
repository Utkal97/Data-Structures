#include "UndirectedGraph_AdjMatrix.h"

using namespace std;

int main() {
    int V=7, E = 0;

    V = 5;
    UndirectedGraph_AdjMatrix UWG(V,E);

    int a[V][V];
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            a[i][j] = 0;
        }
    }

    UWG.initializeGraph((int *)a);    //must type cast to int pointer while passing
    UWG.addEdge(1,2);
    UWG.addEdge(1,5);
    UWG.addEdge(2,3);
    UWG.addEdge(2,4);
    UWG.addEdge(2,5);
    UWG.addEdge(3,4);
    UWG.addEdge(4,5);

    UWG.printAdjMatrix();

    UWG.EulerianPath();

    return 0;
}
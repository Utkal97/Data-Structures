#include<bits/stdc++.h>
#include "DirectedWeightedGraph.h"
using namespace std;

//printMap(map<int, int> given).
void printMap(map<int,int> given) {
    for(map<int,int>::iterator it=given.begin(); it!=given.end(); it++)
        printf("%d : %d\n",it->first, it->second);
    return;
}

int main() {
    int V=7, E = 0;
    map<int, int> path;
    map<int, int> distance;
    
    /*
    DirectedGraph_AdjList DG(V,E);
    map<int, node*> adj;

    DG.initializeGraph(adj);

    DG.addEdge(1,2);
    DG.addEdge(1,3);
    DG.addEdge(1,4);
    DG.addEdge(2,3);
    DG.addEdge(2,5);
    DG.addEdge(3,4);
    DG.addEdge(4,6);
    DG.addEdge(6,7);
    DG.printAdjList();
    DG.DFSTraversal(1);
    DG.BFSTraversal(1);

    map<int, int> distance = DG.shortestPathFrom(1);
    cout<<"Shortest path : "<<endl;
    printMap(distance);

    /////////////////////////////////////////////////////////

    DirectedGraph_AdjMatrix DM(V,E);

    int a[V][V];
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            a[i][j] = 0;
        }
    }

    DM.initializeGraph((int *)a);    //must type cast to int pointer while passing
    DM.addEdge(1,2);
    DM.addEdge(1,3);
    DM.addEdge(1,4);
    DM.addEdge(2,3);
    DM.addEdge(2,5);
    DM.addEdge(3,4);
    DM.addEdge(4,6);
    DM.addEdge(6,7);
    DM.printAdjMatrix();
    DM.DFSTraversal(1);
    DM.BFSTraversal(1);

    distance = DM.shortestPathFrom(1);
    cout<<"Shortest path : "<<endl;
    printMap(distance);

    /////////////////////////////////////////////////////////////////
    
    UndirectedGraph_AdjMatrix G(V,E);
    
    G.initializeGraph((int *)a);    //must type cast to int pointer while passing
    G.addEdge(1,2);
    G.addEdge(1,3);
    G.addEdge(1,4);
    G.addEdge(2,3);
    G.addEdge(2,5);
    G.addEdge(3,4);
    G.addEdge(4,6);
    G.addEdge(6,7); 
	G.printAdjMatrix();

    map<int,int> dist = G.shortestPathFrom(1);
    cout<<"shortest path : "<<endl;
    printMap(dist);
    
    //////////////////////////////////////////////////////

    
    UndirectedGraph_AdjList GL(7,0);

    GL.initializeGraph(adj);

    GL.addEdge(1,2);
    GL.addEdge(1,3);
    GL.addEdge(1,4);
    GL.addEdge(2,3);
    GL.addEdge(2,5);
    GL.addEdge(3,4);
    GL.addEdge(4,6);
    GL.addEdge(6,7);
    GL.printAdjList();

    dist = GL.shortestPathFrom(1);
    cout<<"shortest path : "<<endl;
    printMap(dist);

	///////////////////////////////////////////////////////

	
    G.DFSTraversal(1);
    cout<<endl;
    GL.DFSTraversal(1);
    cout<<endl;

	G.BFSTraversal(1);
    cout<<endl;
    GL.BFSTraversal(1); 
	cout<<endl;

    */
    V = 5;
    UndirectedWeightedGraph UWG(V,E);

    int a[V][V];
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            a[i][j] = 0;
        }
    }

    UWG.initializeGraph((int *)a);    //must type cast to int pointer while passing
    UWG.addEdge(1,2,4);
    UWG.addEdge(1,3,3);
    UWG.addEdge(2,5,4);
    UWG.addEdge(2,3,2);
    UWG.addEdge(3,4,4);
    UWG.addEdge(4,5,4);

    UWG.printAdjMatrix();

    // distance = UWG.shortestPathFrom(1);
    // printMap(distance);


    path = UWG.Prim(1);
    //printMap(path);

    UWG.Kruskal();

    
    cout<<"////////////////////////////////////////////////////////"<<endl;

    DirectedWeightedGraph DWG(V,E);
    DWG.initializeGraph((int *)a);    //must type cast to int pointer while passing
    DWG.addEdge(1,2,4);
    DWG.addEdge(1,3,3);
    DWG.addEdge(2,5,4);
    DWG.addEdge(2,3,2);
    DWG.addEdge(3,4,4);
    DWG.addEdge(4,5,4);
    // DWG.addEdge(5,1,-9);         //This edge forms negative weight cycle.

    DWG.printAdjMatrix();

    //distance = DWG.shortestPathFrom(1);
    //printMap(distance);

    path = DWG.Prim(1);
    //printMap(path);

    DWG.Kruskal();

    return 0;
}

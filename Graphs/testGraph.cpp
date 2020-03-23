#include<bits/stdc++.h>
#include "UndirectedGraph_AdjMatrix.h"
#include "UndirectedGraph_AdjList.h"

using namespace std;

int main() {
    int V=7, E = 0;
    UndirectedGraph_AdjMatrix G(V,E);
    int a[V][V];
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            a[i][j] = 0;
        }
    }
    
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
        
    
    //////////////////////////////////////////////////////

    
    UndirectedGraph_AdjList GL(7,0);

    map<int, node*> adj;

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

	///////////////////////////////////////////////////////

	
    G.DFSTraversal(1);
    cout<<endl;
    GL.DFSTraversal(1);
    cout<<endl;

	G.BFSTraversal(1);
    cout<<endl;
    GL.BFSTraversal(1); 
	cout<<endl; 

    return 0;
}

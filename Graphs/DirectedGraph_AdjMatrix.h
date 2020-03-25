#include "UndirectedGraph_AdjMatrix.h"
using namespace std;

void printMap(map<int,int> given) {
    for(map<int,int>::iterator it=given.begin(); it!=given.end(); it++)
        printf("%d : %d\n",it->first, it->second);
    return;
}

class DirectedGraph_AdjMatrix : public UndirectedGraph_AdjMatrix {
    public :

        DirectedGraph_AdjMatrix(int no_of_vertices, int no_of_edges) : UndirectedGraph_AdjMatrix(no_of_vertices, no_of_edges) {
            return;
        }

        void addEdge(int u, int v) {
            u-=1, v-=1;

            if(inRange(u) && inRange(v) && !adj[u][v]) {
                adj[u][v] = 1;
                E += 1;
            }
            return;
        }

        void deleteEdge(int u, int v) {
            u-=1, v-=1;

            if(inRange(u) && inRange(v) && adj[u][v]) {
                adj[u][v] = 0;
                E -= 1;
            }
            return;
        }

        //Run time : O(V^2). Prints vertices in topologically sorted order.
        void topologicalSort() {
            map<int, int> indegree;
            queue<int> q;
            int visited[V] = {0};

            for(int vertex = 0; vertex<V; vertex++) {
                for(int neigh=0; neigh<V; neigh++) {
                    if(adj[neigh][vertex])
                        indegree[vertex+1]++;
                }
                if(indegree[vertex+1]==0) {
                    visited[vertex] = 1;
                    q.push(vertex+1);
                }
            }

            int count = 0;
            
            while(!q.empty()) {

                int curr = q.front();
                q.pop();

                curr-=1;
                
                cout<<curr+1<<" ";
                count++;

                for(int neigh=0; neigh<V; neigh++) {
                    if(adj[curr][neigh])
                        indegree[neigh+1]--;

                    if(indegree[neigh+1]==0 && !visited[neigh]) {
                        visited[neigh] = 1;
                        q.push(neigh+1);
                    }
                }
            }
            if(count!=V)
                cout<<"Graph has cycle\n";
            cout<<endl;
            return;
        }
};
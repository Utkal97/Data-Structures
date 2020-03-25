#include "UndirectedWeightedGraph.h"

using namespace std;

class DirectedWeightedGraph : public UndirectedWeightedGraph {
    public:
        DirectedWeightedGraph(int no_of_vertices, int no_of_edges) : UndirectedWeightedGraph(no_of_vertices, no_of_edges) {
            return;
        }

        void addEdge(int u, int v, int weight) {
            u-=1, v-=1;
            if(inRange(u) && inRange(v)) {
                if(adj[u][v]==0)
                    E++;
                adj[u][v] = weight;
            }
            return;
        }

        void removeEdge(int u, int v) {
            u -=1, v-=1;
            if(inRange(u) && inRange(v) && adj[u][v]!=0) {
                E--;
                adj[u][v] = 0;
            }
            return;
        }

        //Prims(int vertex). Run time : O(ElogV) with binary Heaps.
        map<int, int> Prims(int vertex) {
            cout<<"Minimum Spanning Tree with Prim's Algorithm :-"<<endl;
            if(!inRange(vertex-1))
                return {};

            map<int,int> distance, path;
            for(int i=1;i<=V;i++) {
                distance[i] = -1;
            }
            distance[vertex] = 0;

            //min heap that considers first property for priority(in our case distance).
            set< pair<int,int> > dist_set;
            dist_set.insert(make_pair(0, vertex));

            while(!dist_set.empty()) {
                
                pair<int,int> curr = *(dist_set.begin());
                dist_set.erase(dist_set.begin());

                vertex = curr.second;
                
                for(int neighbour=0; neighbour < V; neighbour++) {
            
                    if(adj[vertex-1][neighbour]) {

                        int new_distance = distance[vertex] + adj[vertex-1][neighbour];

                        //if distance is calculated first time, add to set
                        if(distance[neighbour+1] == -1) {
                            distance[neighbour+1] = adj[vertex-1][neighbour];
                            dist_set.insert(make_pair(distance[neighbour+1], neighbour+1));
                            path[neighbour+1] = vertex;
                        }
                        //if distance is already calculated, update distance by removing and inserting again into set
                        else if(distance[neighbour+1] > new_distance) {
                            dist_set.erase(dist_set.find(make_pair(distance[neighbour+1], neighbour+1)));
                            distance[neighbour+1] = adj[vertex-1][neighbour];
                            dist_set.insert(make_pair(distance[neighbour+1], neighbour+1));
                            path[neighbour+1] = vertex;
                        }
                    }
                }
            }

            return path;
        }


        void Kruskal() {

            //set of edges of given graph
            set<struct edge> edge_set;
            printAdjMatrix();
            for(int vertex = 0; vertex<V; vertex++) {
                for(int neighbour = 0; neighbour<V; neighbour++) {
                    if(adj[vertex][neighbour])
                        edge_set.insert({adj[vertex][neighbour], vertex+1, neighbour+1});
                }
            }
            
            //MST is a set that contains edges of Minimum Spanning Tree
            set<struct edge> MST;

            //tree number that given vertex belongs to
            int tree[V];

            for(int i=0;i<V;i++) {
                tree[i] = i+1;
            }

            for(set<struct edge>::iterator it = edge_set.begin(); it!=edge_set.end(); it++) {
                if(tree[it->src] != tree[it->dest]) {
                    tree[it->src] = min(tree[it->src], tree[it->dest]);
                    MST.insert(*it);
                }
            }

            cout<<"Minimum Spanning Tree with Kruskal's Algorithm :-"<<endl;
            for(set<struct edge>::iterator it = MST.begin(); it!=MST.end(); it++) {
                printf("%d : %d %d\n",it->weight, it->src, it->dest);
            }
            return;
        }
};
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

        //Prim(int vertex). Run time : O(ElogV) using binary Heaps.
        map<int, int> Prim(int vertex) {
            
            cout<<"Minimum Spanning Tree with Prim's Algorithm :-"<<endl;
            
            if(!inRange(vertex-1))
                return {};

            map<int,int> distance, parent;
            for(int i=1; i<=V; i++) {
                distance[i] = -1;
            }
            distance[vertex] = 0;
            parent[vertex] = 0;

            //min heap that considers first property as priority(in our case distance).
            set< pair<int,int> > dist_set;
            dist_set.insert(make_pair(0, vertex));

            while(!dist_set.empty()) {

                pair<int,int> curr = *(dist_set.begin());
                dist_set.erase(dist_set.begin());

                vertex = curr.second;

                for(int neighbour = vertex; neighbour < V; neighbour++) {

                    if(adj[vertex-1][neighbour]) {

                        int new_distance = distance[vertex] + adj[vertex-1][neighbour];

                        //if distance is calculated first time, add to set
                        if(distance[neighbour+1] == -1) {
                            distance[neighbour+1] = adj[vertex-1][neighbour];
                            parent[neighbour+1] = vertex;
                            
                            dist_set.insert(make_pair(distance[neighbour+1], neighbour+1));
                        }
                        //if distance is already calculated, update distance by removing and inserting again into set
                        else if(distance[neighbour+1] > new_distance) {
                            dist_set.erase(dist_set.find(make_pair(distance[neighbour+1], neighbour+1)));
                            
                            distance[neighbour+1] = adj[vertex-1][neighbour];
                            parent[neighbour+1] = vertex;
                            
                            dist_set.insert(make_pair(distance[neighbour+1], neighbour+1));
                        }
                        //printf("Checking src : %d, dest : %d distance : %d\n",vertex, neighbour+1, distance[neighbour+1]);
                    }
                }
            }

            //MST is the set of edges in Minimum Spanning Tree
            set<struct edge> MST;
            cout<<"MST :-"<<endl;
            for(int i=1; i<=V; i++) {
                MST.insert({distance[i], parent[i], i});
            }
            for(set<struct edge>::iterator it = MST.begin(); it!=MST.end(); it++) {
                printf("%d : %d %d\n",it->weight, it->src, it->dest);
            }

            return parent;
        }

        //Kruskal(). Run time : O(V^2) for adjacency matrix. Gives Minimum Spanning Tree
        void Kruskal() {

            cout<<"Minimum Spanning Tree with Kruskal's Algorithm :-"<<endl;
            
            //set of edges of given graph
            set<struct edge> edge_set;
            
            for(int vertex = 0; vertex<V; vertex++) {
                for(int neighbour = 0; neighbour<V; neighbour++) {
                    if(adj[vertex][neighbour])
                        edge_set.insert({adj[vertex][neighbour], vertex+1, neighbour+1});
                }
            }

            //trees is a Forest of trees (disjoint sets)
            DisjointSet trees(V);

            //MST : Minimum Spanning Tree. Set of edges (weight, src, dest)
            set<struct edge> MST;

            for(set<struct edge>::iterator it = edge_set.begin(); it != edge_set.end(); it++) {

                if( trees.Find(it->src) != trees.Find(it->dest)) {
                    //printf("Joining %d %d\n",it->src, it->dest);
                    trees.Union(it->src, it->dest);
                    MST.insert({it->weight, it->src, it->dest});
                }
            }
            
            for(set<struct edge>::iterator it = MST.begin(); it!=MST.end(); it++) {
                printf("%d : %d %d\n",it->weight, it->src, it->dest);
            }
            return;
        }
};
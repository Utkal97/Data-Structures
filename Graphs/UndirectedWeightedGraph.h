#include<bits/stdc++.h>
#include "UndirectedGraph_AdjMatrix.h"
#include "./../Disjoint Sets/DisjointSet_Ranking.h"
using namespace std;

int min(int x, int y) {
    return x<y ? x : y;
}

//contains weight, src, dest
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

//createEdge(int weight, int source, int destination). Creates a struct instance edge
edge* createEdge(int weight, int source, int destination) {
    edge *newEdge = new edge;
    newEdge->weight = weight;
    newEdge->src = source;
    newEdge->dest = destination;

    return newEdge;
}

class UndirectedWeightedGraph : public UndirectedGraph_AdjMatrix {
    public:
        UndirectedWeightedGraph(int no_of_vertices, int no_of_edges) : UndirectedGraph_AdjMatrix(no_of_vertices, no_of_edges) {
            return;
        }

        void addEdge(int u, int v, int weight) {
            u-=1, v-=1;

            if(inRange(u) && inRange(v)) {
                adj[u][v] = weight;
                adj[v][u] = weight;
                E += 1;
            }
            return;
        }

        //Call this if you are not sure whether negative edges exist or not
        map<int, int> shortestPathFrom(int vertex) {
            if(!inRange(vertex-1))
                return {};

            bool negative_edge = false;
            for(int v=0; v<V; v++) {
                for(int n=0;n<V;n++) {
                    if(adj[v][n] < 0) {
                        negative_edge = true;
                        break;
                    }
                }
                if(negative_edge)
                    break;
            }

            if(!negative_edge)
                return Dijkstra(vertex);
            else
                return BellmanFord(vertex);
        }

        //Dijkstra(int vertex). Run-time : O(V^2) for Adjacency matrix. Doesn't work for negative edge.
        map<int, int> Dijkstra(int vertex) {

            cout<<"Dijkstra O(V^2) for Adjacency Matrix"<<endl;

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


                        if(distance[neighbour+1] == -1) {
                            distance[neighbour+1] = new_distance;
                            dist_set.insert(make_pair(distance[neighbour+1], neighbour+1));
                            path[neighbour+1] = vertex;
                        }
                        else if(distance[neighbour+1] > new_distance) {
                            dist_set.erase(dist_set.find(make_pair(distance[neighbour+1], neighbour+1)));
                            distance[neighbour+1] = new_distance;
                            dist_set.insert(make_pair(distance[neighbour+1], neighbour+1));
                            path[neighbour+1] = vertex;
                        }
                    }
                }
            }

            return distance;
        }

        //BellmanFord(int vertex). Run-time : O(V^3) for Adjacency matrix. Works for negative edge.
        map<int, int> BellmanFord(int vertex) {
            if(!inRange(vertex-1))
                return {};

            cout<<"BellmanFord O(V^3) for Adjacency Matrix"<<endl;

            map<int,int> distance;
            for(int ind = 1; ind <=V; ind++) {
                distance[ind] = INT_MAX;
            }
            distance[vertex] = 0;

            //relax edges V-1 times.
            for(int it=1;it<V;it++) {
            
                //for every edge, check and update if lesser distance is found.
                for(int vertex=0; vertex<V; vertex++) {
                    for(int neighbour=0; neighbour<V; neighbour++) {
            
                        if(adj[vertex][neighbour]) {
                            int new_distance = distance[vertex+1] + adj[vertex][neighbour];
                            
                            if(distance[neighbour+1] > new_distance)
                                distance[neighbour+1] = new_distance;
                        }
                    }
                }
            }

            //after relaxing V-1 times, check if there exists further less distance for any edge.
            for(int vertex=0; vertex<V; vertex++) {
                for(int neighbour=0; neighbour<V; neighbour++) {

                    if(adj[vertex][neighbour]!=0) {
                        int new_distance = distance[vertex+1] + adj[vertex][neighbour];

                        //if so, there is no solution.
                        if(distance[neighbour+1] > new_distance) {
                            printf("Graph has negative weight cycle.\n");
                            return {};
                        }
                    }
                }
            }
            
            return distance;
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
                for(int neighbour = vertex+1; neighbour<V; neighbour++) {
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

        //INCOMPLETE
        vector<int> findAP(int vertex, vector<int> &AP) {
            
        }

        //INCOMPLETE :- articulatoinPoints(). Run time : O(V+E) (since, DFS). Gives out all the cut vertices of Graph.
        vector<int> articulationPoints() {
            vector<int> AP;
            int parent[V] = {-1};
            parent[1] = 1;
            return findAP(1,AP);
        }
};
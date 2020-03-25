#include "UndirectedGraph_AdjList.h"

using namespace std;

class DirectedGraph_AdjList : public UndirectedGraph_AdjList {
    public :

        DirectedGraph_AdjList(int no_of_vertices, int no_of_edges) : UndirectedGraph_AdjList(no_of_vertices, no_of_edges) {
            return;
        }

        void addEdge(int u, int v) {

            node *u_head = adjList[u];
            bool edge_added = false;

            if(u_head) {
                while(u_head && u_head->next) {
                    if(u_head->data == v)
                        break;
                    u_head = u_head->next;
                }

                u_head->next = createNode(v);
                edge_added = true;
            }
            else {
                adjList[u] = createNode(v);
                edge_added = true;
            }

            if(edge_added)
                E++;

            return;
        }

        void removeEdge(int u, int v) {

            node *u_neighbour = adjList[u];
            bool edge_deleted = false;
            
            if(u_neighbour) {
                node* parent = NULL;
                while(u_neighbour && u_neighbour->data != v) {
                    parent = u_neighbour;
                    u_neighbour = u_neighbour->next;
                }

                if(u_neighbour && u_neighbour->data == v) {
                    node *temp = u_neighbour;
                    if(adjList[u] == u_neighbour)
                        adjList[u] = u_neighbour->next;
                    else
                        parent->next = u_neighbour->next;
                    free(temp);
                    edge_deleted = true;
                }
            }

            if(edge_deleted)
                E--;
            return;
        }

        //Run time: O(|V| + |E|).  Prints vertices in topologically sorted order.
        void topologicalSort() {

            map<int, int> indegree;
            for(int vertex=1; vertex<=V; vertex++) {
                node* neighbour = adjList[vertex];
                while(neighbour) {
                    indegree[neighbour->data]++;
                    neighbour = neighbour->next;
                }
            }

            queue<int> q;
            for(int vertex=1; vertex<=V; vertex++) {
                if(indegree[vertex]==0)
                    q.push(vertex);
            }

            int count = 0;
            while(!q.empty()) {

                int curr = q.front();
                q.pop();
                cout<<curr<<" ";
                count++;

                node* neighbour = adjList[curr];
                while(neighbour) {

                    int neigh = neighbour->data;
                    indegree[neigh]--;

                    if(indegree[neigh] == 0)
                        q.push(neigh);

                    neighbour = neighbour->next;
                }
            }

            if(count != V)
                cout<<"Graph is cyclic.";
    
            cout<<endl;
            return;
        }
};
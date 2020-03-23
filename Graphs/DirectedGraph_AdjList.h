#include "UndirectedGraph_AdjList.h"

using namespace std;

class DirectedGraph_AdjList : public UndirectedGraph_AdjList {
    public :
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
};
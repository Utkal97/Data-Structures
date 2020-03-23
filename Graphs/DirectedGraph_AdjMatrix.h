#include "UndirectedGraph_AdjMatrix.h"
using namespace std;

class DirectedGraph_AdjMatrix : public UndirectedGraph_AdjMatrix {
    public :
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
};
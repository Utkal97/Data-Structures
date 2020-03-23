#include<bits/stdc++.h>

using namespace std;

void printArray2(int array[], int size) {
    for(int i=0;i<size;i++) {
        printf("%d ",array[i]);
    }
    cout<<endl;
    return;
}

class UndirectedGraph_AdjMatrix {
    protected:
        int V;
        int E;
        int **adj;

        bool inRange(int x) {
            if(0<=x && x<=V)
                return true;
            return false;
        }

    public:

        UndirectedGraph_AdjMatrix(int no_of_vertices, int no_of_edges) {
            V = no_of_vertices;
            E = no_of_edges;
            adj = (int **)malloc(V * sizeof(int *)); 
            for (int i=0; i<V; i++) 
                adj[i] = (int *)malloc(V * sizeof(int)); 
            
            return;
        }

        void initializeGraph(int *G) {
            for(int row = 0; row < V; row++) {
                for(int col = 0; col < V; col++) {
                    adj[row][col] = *(G + row*V + col); //dereference pointer value
                }
            }
        }

        void removeEdge(int v, int u) {
            v-=1, u-=1;

            if(inRange(v) && inRange(u) && adj[u][v]) {
                adj[v][u] = 0;
                adj[u][v] = 0;
                E -= 1;
            }
            return;
        }

        void addEdge(int v, int u) {
            v-=1, u-=1;

            if(inRange(v) && inRange(u) && !adj[u][v]) {
                adj[v][u] = 1;
                adj[u][v] = 1;
                E+=1;
            }
            return;
        }

        void DFS(int vertex, int visited[]) {
            vertex-=1;
            if(visited[vertex])
                return;
            
            visited[vertex] = 1;
            cout<<vertex+1<<" ";
            
            for(int ind = 0; ind<V; ind++) {
                if(adj[vertex][ind] && !visited[ind])
                    DFS(ind+1, visited);
            }
        }

        void DFSTraversal(int vertex) {
            printf("DFS(%d) : ",vertex);
            int visited[V] = {0};

            DFS(vertex, visited);

            cout<<endl<<"visited array : ";
            printArray2(visited,V);
            return;
        }

        void BFSTraversal(int vertex) {
            printf("BFS(%d) : ",vertex);
            vertex -= 1;
            queue<int> q;
            q.push(vertex);
            int visited[V] = {0};
            visited[vertex] = 1;

            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                printf("%d ",curr+1);

                for(int ind = 0; ind<V; ind++) {
                    if(adj[curr][ind] && !visited[ind]) {
                        q.push(ind);
                        visited[ind] = 1;
                    }
                }
            }
            
            cout<<endl<<"visited array : ";
            printArray2(visited,V);
            return;
        }

        void printAdjMatrix() {
            cout<<"Adjacency Matrix :-"<<endl;
            for(int i = 0; i<V; i++) {
                for(int j = 0; j<V; j++) {
                    printf("%d ",adj[i][j]);
                }
                printf("\n");
            }
            printf("Total vertices : %d and Total Edges : %d\n",V,E);
            return;
        }
};

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
            if(0<=x && x<V)
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

        //initializeGraph(int *array). Type case your 2D array to int pointer while passing.
        void initializeGraph(int *arr) {
            for(int row = 0; row < V; row++) {
                for(int col = 0; col < V; col++) {
                    adj[row][col] = *(arr + row*V + col); //dereference pointer value
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

        //DFS(int vertex, int visited[]). Run-time : O(V). Pass an array of int of size >= V, initialized to zeros.
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

        //DFSTraversal(int vertex). Run-time: O(V).
        void DFSTraversal(int vertex) {
            if(!inRange(vertex-1)) {
                cout<<"Given vertex not in range"<<endl;
                return;
            }
            printf("DFS(%d) : ",vertex);
            int visited[V] = {0};

            DFS(vertex, visited);

            cout<<endl<<"visited array : ";
            printArray2(visited,V);
            return;
        }

        //BFSTraversal(int vertex). Run-time: O(V).
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

        //shortestPathFrom(int vertex). Run time : O(V). Uses BFS.
        map<int, int> shortestPathFrom(int vertex) {
            if(!inRange(vertex-1))
                return {};

            map<int, int> distance;
            int visited[V] = {0};

            distance[vertex] = 0;

            queue<int> q;
            q.push(vertex);

            while(!q.empty()) {
                vertex = q.front();
                q.pop();

                int visited_ind = vertex-1;

                visited[visited_ind] = 1;
                for(int nei = 0; nei <V; nei++) {
                    if(adj[visited_ind][nei] &&!visited[nei]) {
                        distance[nei+1] = distance[vertex]+1;
                        visited[nei] = 1;
                        q.push(nei+1);
                    }
                }

            }
            
            return distance;
        }
};

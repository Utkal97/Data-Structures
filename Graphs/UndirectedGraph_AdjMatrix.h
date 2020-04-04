#include<bits/stdc++.h>
#include "./../Linked Lists/SinglyLinkedListClass.h"
using namespace std;

void printArray2(int array[], int size) {
    for(int i=0;i<size;i++) {
        printf("%d ",array[i]);
    }
    cout<<endl;
    return;
}

struct unweightedEdge {
    int src;
    int dest;
};

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

        //EulerianExists(). Run time : O(V^2). Returns 0 : if no Eulerian walk exists. 1 : if Eulerian Path exists. 2 : if Eulerian Circuit exists
        int EulerianExists() {

            //contains degree of each vertex.
            map<int, int> degree;

            //counts the number of vertices with Odd degree.
            int oddDegree = 0;
            
            for(int vertex=0; vertex<V; vertex++) {
                for(int neighbour = 0; neighbour < V; neighbour++) {
                    if(adj[vertex][neighbour])
                        degree[vertex+1]++;
                }
                if(degree[vertex+1] % 2 != 0)
                    oddDegree++;
            }

            if(oddDegree == 2)
                return 1;
            else if(oddDegree == 0)
                return 2;
            else {
                cout<<"No Eulerian walk exists for given graph"<<endl;
                return 0;
            }
        }

        Node* DFSEulerPath(int vertex, map<int, Node*> adjList, int edges) {
            if(edges <= 0)
                return NULL;
            
            
            return NULL;
        }

        //EulerianPath().
        vector<int> EulerianPath() {
            //contains src in first index(0) and dest in second index(1).
            vector<int> SrcDest = EulerianPathExists();
            if(SrcDest.size()==0) {
                cout<<"Eulerian Path doesn't exist for graph."<<endl;
                return {};
            }

            cout<<"Eulerian Path :- "<<endl;
            SinglyLinkedList Path;
            Path.append(SrcDest[0]);
            int no_of_edges = E;

            map<int, Node*> adjList = getADJList();

            Node* EulerPathHead = DFSEulerPath(SrcDest[0],adjList, no_of_edges);
            Path.setHead(EulerPathHead);
            return {};
        }

        //EulerianPathExists(). Run time O(V^2). If path exists, returns vector<int> of size 2. Otherwise, empty vector<int> is returned.
        vector<int> EulerianPathExists() {

            //contains degree of each vertex.
            map<int, int> degree;

            int oddDegree = 0, src, dest;

            //tells if src is already set.
            bool srcSet = false;

            for(int vertex=0; vertex<V; vertex++) {

                for(int neighbour = 0; neighbour < V; neighbour++) {
                    if(adj[vertex][neighbour])
                        degree[vertex+1]++;
                }

                if(degree[vertex+1] % 2 != 0) {
                    if(!srcSet)
                        src = vertex+1;
                    else
                        dest = vertex+1;
                    oddDegree++;
                }
            }

            if(oddDegree==2)
                return {src, dest};
            else
                return {};
        }

        //renders adjacency list from adjacency matrix of graph of the instance
        map<int, Node*> getADJList() {
            map<int, Node *> adjList;

            for(int vertex = 0; vertex<V; vertex++) {
                SinglyLinkedList list;

                for(int nei = 0; nei<V; nei++) {
                    if(adj[vertex][nei])
                        list.append(nei+1);
                }

                adjList[vertex+1] = list.getHead();
            }

            for(map<int, Node*>::iterator it=adjList.begin(); it!=adjList.end(); it++) {
                printf("%d : ");
                while(it->second) {
                    cout<<it->second->data<<" ";
                }
                cout<<endl;
            }
            return adjList;
        }
};
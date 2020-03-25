#include<bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* next;
};

node* createNode(int value) {
    node* newNode = new(nothrow) node;
    if(!newNode) {
        printf("Memory Error!");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(node* head) {
    while(head) {
        cout<<head->data;
        head= head->next;
        if(head)
            printf(", ");
    }
    cout<<endl;
    return;
}

void printArray(int array[], int size) {
    for(int i=0;i<size;i++) {
        printf("%d ",array[i]);
    }
    cout<<endl;
    return;
}

class UndirectedGraph_AdjList {
    protected:
        int V;
        int E;
        map<int, node*> adjList;

        bool inRange(int x) {
            if(1<=x && x<=V)
                return true;
            return false;
        }

    public:

        UndirectedGraph_AdjList(int no_of_vertices, int no_of_edges) {
            V = no_of_vertices;
            E = no_of_edges;

            for(int vertex=1; vertex<=V; vertex++)
                adjList[vertex] = NULL;

            return;
        }
        
        //initializeGraph(map<int, node*> list). Run time : O(V).
        void initializeGraph(map<int, node*> list) {
            for(map<int, node*>::iterator it=list.begin(); it!=list.end(); it++) {
                adjList[it->first] = it->second;
            }
            return;
        }

        void addEdge(int u, int v) {

            node *v_head = adjList[v], *u_head = adjList[u];
            bool edge_added = false;

            if(v_head) {
                while(v_head && v_head->next) {
                    if(v_head->data == u)
                        break;
                    v_head = v_head->next;
                }

                v_head->next = createNode(u);
                edge_added = true;
            }
            else {
                adjList[v] = createNode(u);
                edge_added = true;
            }

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

            node *v_neighbour = adjList[v], *u_neighbour = adjList[u];
            bool edge_deleted = false;
            if(v_neighbour) {
                node* parent = v_neighbour;
                while(v_neighbour && v_neighbour->data != u) {
                    parent = v_neighbour;
                    v_neighbour = v_neighbour->next;
                }

                if(v_neighbour && v_neighbour->data == u) {
                    node *temp = v_neighbour;

                    if(adjList[v] == v_neighbour)
                        adjList[v] = v_neighbour->next;
                    else
                        parent->next = v_neighbour->next;
                    free(temp);
                    edge_deleted = true;
                }
            }
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

        //DFS(int vertex,int visited[]). Run time : O(V). visited array size >= V, whose all elements are initialized to zero. 
        void DFS(int vertex, int visited[]) {
            vertex-=1;
            if(visited[vertex])
                return;
            
            visited[vertex] = 1;
            printf("%d ",vertex+1);
            node* neighbour = adjList[vertex+1];
            while(neighbour) {
                if(!visited[neighbour->data-1]) {
                    int neigh = neighbour->data;
                    //cout<<vertex<<" is not visited"<<endl;
                    DFS(neigh, visited);
                }
                
                neighbour = neighbour->next;
            }
            return;
        }

        //DFSTraversal(int vertex). Run time : O(V).
        void DFSTraversal(int vertex) {
            printf("DFS(%d) : ", vertex);
            int visited[V] = {0};
            DFS(vertex, visited);
            cout<<endl<<"visited array : ";
            printArray(visited,V);
            return;
        }

        //BFSTraversal(int vertex). Run time : O(V).
        void BFSTraversal(int vertex) {
            printf("BFS(%d) : ",vertex);
            queue<int> q;
            int visited[V] = {0};
            q.push(vertex);
            visited[vertex-1] = 1;
            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                printf("%d ",curr);
                
                node *neighbour = adjList[curr];
                while(neighbour) {
                    if(!visited[neighbour->data - 1]) {
                        q.push(neighbour->data);
                        visited[neighbour->data - 1] = 1;
                    }
                    neighbour = neighbour->next;
                }
            }
            cout<<endl<<"visited array : ";
            printArray(visited,V);
            return;
        }

        //shortestPathFrom(int vertex). Run time : O(V). Uses BFS
        map<int,int> shortestPathFrom(int vertex) {
            int visited[V] = {0};

            map<int, int> distance;
            distance[vertex] = 0;
            queue<int> q;
            q.push(vertex);

            while(!q.empty()) {
                vertex = q.front();
                q.pop();
                visited[vertex-1] = 1;

                node* neighbourNode = adjList[vertex];
                while(neighbourNode) {
                    int neighbour = neighbourNode->data;

                    if(!visited[neighbour-1]) {
                        visited[neighbour-1] = 1;
                        distance[neighbour] = distance[vertex] + 1;
                        q.push(neighbour);
                    }
                    neighbourNode = neighbourNode->next;
                }
            }

            return distance;
        }

        //Prints Adjacency List
        void printAdjList() {
            printf("Adjacency List :-\n");
            for(map<int, node*>::iterator it=adjList.begin(); it!=adjList.end(); it++) {
                cout<<it->first<<" : ";
                printList(it->second);
            }
            printf("Total vertices : %d and Total Edges : %d\n",V,E);
            return;
        }
};

#include<bits/stdc++.h>

using namespace std;

class DisjointSet {
    protected:
        int N;
        int *parent;
        int *rank;

    public:
        DisjointSet(int n) {
            N = n;
            parent = new int[N];
            rank = new int[N];
            makeSet();
            return;
        } 

        void makeSet() {
            for(int i=0;i<N;i++) {
                parent[i] = i;
                rank[i] = 0;
            }
            return;
        }

        int Find(int x) {

            if(parent[x] !=x) {

                int result = Find(parent[x]);

                //cache the result so its useful next time
                parent[x] = result;
            }

            return parent[x];
        }

        void Union(int x, int y) {

            int set_x_rep = Find(x);
            int set_y_rep = Find(y);

            if(set_x_rep == set_y_rep)
                return;
            
            if(rank[set_x_rep] < rank[set_y_rep]) {
                parent[set_x_rep] = set_y_rep;
            }
            else if(rank[set_x_rep] > rank[set_y_rep]) {
                parent[set_y_rep] = set_x_rep;
            }
            else {
                parent[set_x_rep] = set_y_rep;
                rank[set_y_rep] += 1;
            }
            return;
        }
};
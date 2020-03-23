#include<bits/stdc++.h>

using namespace std;

void function(int a, int b, int **arr) {
    int n[a][b];
    for(int i=0;i<a;i++) {
        for(int j=0;j<b;j++) {
            n[i][j] = arr[i][j];
            cout<<n[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

int main() {
	int **a= new int*[2];
	for(int i=0;i<2;i++) {
		a[i] = new int[2];
	}
	
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			a[i][j] = 1;
		}
	}
    int arr[2][2] = {{1,0}, {0,1}};
    function(2,2,a);
    return 0;
}

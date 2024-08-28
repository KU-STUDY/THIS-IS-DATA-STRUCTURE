#include <iostream>

using namespace std;

int n,m;
int adj[100][100];

int main(void) {
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
}
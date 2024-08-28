#include <iostream>
#include <vector>

using namespace std;
vector<int> adj[10];

int n, m;

int main(void) {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
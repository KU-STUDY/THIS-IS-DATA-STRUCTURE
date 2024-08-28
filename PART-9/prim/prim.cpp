#include <iostream>
#include <vector>

using namespace std;

int n,m, answer;
int dist[1000];
bool select[1000];
vector<pair<int,int>> cost[1000];


int main(void) {
    dist[1] = 0;
    select[1] = true;
    for(int i=0; i<cost[1].size(); i++) {
        int next = cost[1][i].first;
        int distance = cost[1][i].second;
        dist[next] = distance;
    }

    for (int i=1; i<=n-1; i++) {
        int min_cost = INFINITY;
        int min_idx = -1;
        for(int j=1; j<=n; j++) {
            if(select[j] == true) continue;
            if(min_cost > dist[j]) {
                min_cost = dist[j];
                min_idx = j;
            }
        }

        select[min_idx] = true;
        answer = answer + min_cost;

        for (int j=0; j< cost[min_idx].size(); j++) {
            int next = cost[min_idx][j].first;
            int distance = cost[min_idx][j].second;

            if(select[next] == true) continue;
            if(dist[next] > distance) dist[next] = distance;
        }
}
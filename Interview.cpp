#include <bits/stdc++.h>
using namespace std;
#define ll int

vector <pair <int , int>> graph[1000];

int nodes , edges , fuelCapacity;
int dp[1000];
int parent[1000];
int visited[1000];

void dijkstras(int start) {
    for(int i = 2 ; i <= nodes ; i++) {
        dp[i] = INT_MAX;
    }

    dp[1] = 0;

    priority_queue <pair <ll , ll>> pq;

    pq.push({0 , 1});
    parent[1] = 1;

    while(!pq.empty()) {
        pair <int , int> cur = pq.top();
        pq.pop();

        int dist = -cur.first;
        int curNode = cur.second;
        visited[curNode] = 1;

        for(auto i : graph[curNode]) {
            if(!visited[i.first]) {
                if(dp[i.first] > dist + i.second) {
                    dp[i.first] = dist + i.second;
                    pq.push({-dp[i.first] , i.first});
                    parent[i.first] = curNode;
                }
            }
        }
    }
}

int main() {
    cin >> nodes >> edges >> fuelCapacity;

    memset(parent , 0 , sizeof(parent));
    memset(visited , 0 , sizeof(visited));

    for(int i = 0 ; i < edges ; i++) {
        ll u , v , w;
        cin >> u >> v >> w;

        graph[u].push_back({v , w});
        graph[v].push_back({u , w});
    }

    dijkstras(1);

    int ans = 0;

    for(int i = 1 ; i <= nodes ; i++) {
        ll curAns = 0;
        if(dp[i] <= fuelCapacity) {
            int pos = i;
            while(parent[pos] != pos) {
                curAns ++;
                pos = parent[pos];
            }
            ans = max(curAns , ans);
        }
    }

    cout << ans + 1 << endl;
    return 0;
}

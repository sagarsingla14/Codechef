#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> graph[1001];
vector <ll> ans(1001);
ll visited[1001];
ll s , n , m;

void bfs() {
    visited[s] = 1;
    ans[s] = 0;
    queue <ll> q;
    q.emplace(s);
    while(!q.empty()) {
        ll parent = q.front();
        // cout << "parent " << parent << endl;
        q.pop();
        for(auto i : graph[parent]) {
            if(!visited[i]) {
                // cout << "child - > " << i << endl;
                ans[i] = ans[parent] + 6;
                q.emplace(i);
                visited[i] = 1;
            }
            else{
                // cout << "child - > " << i << endl;
                // ans[i] = min(ans[i] , ans[parent] + 6);
            }
        }
    }
}

void printAns() {
    for(ll i = 1 ; i <= n ; i++) {
        if(i != s) {
            if(ans[i] == 0) {
                cout << -1 << " ";
            }
            else{
                cout << ans[i] << " ";
            }
        }
    }
    cout << endl;
    ans.clear();
}

void clearGraph() {
    for(ll i = 0 ; i <= n ; i++) {
        graph[i].clear();
    }
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        ll degree[n + 1] = {0};
        for(ll i = 0 ; i < m ; i++) {
            ll u , v;
            cin >> u >> v;
            degree[u] ++;
            degree[v] ++;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cin >> s;
        if(degree[s] == 0) {
            for(ll i = 1 ; i <= n ; i++) {
                if(i != s) {
                    cout << -1 << " ";
                }
            }
            cout << endl;
            continue;
        }

        memset(visited , 0 , sizeof(visited));

        bfs();

        for(ll i = 1 ; i <= n ; i++) {
            if(degree[i] == 0) {
                ans[i] = -1;
            }
        }

        printAns();

        clearGraph();
    }
    return 0;
}

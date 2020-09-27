#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m , degree = 0;
vector <ll> graph[200001];
ll visited[200001] = {0};
vector <pair <ll , ll>> v;
map <ll , ll> mp;

void bfs(ll start) {
    visited[start] = 1;
    queue <ll> q;
    q.push(start);
    while(!q.empty()) {
        ll val = q.front();
        q.pop();
        for(auto i : graph[val]) {
            if(!visited[i]) {
                visited[i] = 1;
                v.push_back({val , i});
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        mp[u] ++;
        mp[v] ++;
    }

    memset(visited , 0 , sizeof(visited));

    ll root , mx = 0;
    for(auto i : mp) {
        if(i.second >= mx) {
            root = i.first;
            mx = i.second;
        }
    }

    bfs(root);

    for(auto i : v) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}

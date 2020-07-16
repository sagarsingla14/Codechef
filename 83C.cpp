#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> graph[500001];
ll visited[500001];
ll inDegree[500001];
ll outDegree[500001];
map <pair <ll , ll> , ll> mp;
ll start , e , mn;
ll n , p , ans = 0;

void dfs(ll s) {
    visited[s] = 1;
    if(inDegree[s] == 1 && outDegree[s] == 0) {
        e = s;
        return ;
    }
    for(auto i : graph[s]) {
        if(!visited[i]) {
            mn = min(mn , mp[{s , i}]);
            dfs(i);
        }
    }
}

void countAns() {
    for(ll i = 1 ; i <= n ; i++) {
        if(outDegree[i] == 1 && inDegree[i] == 0) {
            ans ++;
        }
    }
}

int main() {
    memset(visited , 0 , sizeof(visited));
    memset(outDegree , 0 , sizeof(outDegree));
    memset(inDegree , 0 , sizeof(inDegree));

    cin >> n >> p;
    for(ll i = 0 ; i < p ; i++) {
        ll u , v , w;
        cin >> u >> v >> w;
        graph[u].push_back(v);
        outDegree[u] ++;
        inDegree[v] ++;
        mp[{u , v}] = w;
        mp[{v , u}] = w;
    }

    countAns();
    cout << ans << endl;
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i] && outDegree[i] == 1 && inDegree[i] == 0) {
            mn = 1e18;
            start = i;
            e = 0;
            dfs(i);
            cout << start << " " << e << " " << mn << endl;
        }
    }

    return 0;
}

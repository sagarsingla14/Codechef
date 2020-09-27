#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m;
vector <ll> graph[100001];
ll visited[100001] = {0};
ll parent[100001] = {0};

void dfs(ll start , vector <ll> &component) {
    visited[start] = 1;
    component.push_back(start);
    for(auto i : graph[start]) {
        if(!visited[i]) {
            parent[i] = start;
            dfs(i , component);
        }
    }
}

void cycle(ll start , ll &ok) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            cycle(i , ok);
        }
        else{
            if(parent[start] != i) {
                ok = 0;
                return;
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
    }

    vector <vector <ll>> components;
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            vector <ll> component;
            parent[i] = i;
            dfs(i , component);
            components.push_back(component);
        }
    }

    memset(visited , 0 , sizeof(visited));

    ll ans = 0;
    for(ll i = 0 ; i < components.size() ; i++) {
        if(components[i].size() <= 2) {
            ans ++;
        }
        else{
            ll ok = 1;
            cycle(components[i][0] , ok);
            if(ok) {
                ans ++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

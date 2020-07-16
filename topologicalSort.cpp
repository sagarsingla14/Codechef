#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> graph[100001];
ll visited[100001];
ll n , e;
stack <ll> ans;

void dfs(ll u) {
    visited[u] = 1;
    for(ll i = 0 ; i < graph[u].size() ; i++) {
        if(!visited[graph[u][i]]) {
            dfs(graph[u][i]);
        }
    }
    ans.push(u);
}

void topo() {
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

void printSolution() {
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}

void make_edge(ll u , ll v) {
    graph[u].push_back(v);
}

int main() {
    memset(visited , 0 , sizeof(visited));
    cin >> n >> e;
    for(ll i = 0 ; i < e ; i++) {
        ll u , v;
        cin >> u >> v;
        make_edge(u , v);
    }

    topo();
    printSolution();
    return 0;
}

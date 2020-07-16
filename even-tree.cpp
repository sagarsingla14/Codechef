#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
    Node *left;
    Node *right;
    ll data;
};

vector <ll> graph[1001];
vector <ll> visited(1001);
ll ans;

ll dfs(ll start) {
    visited[start] = 1;
    ll curNodeChilds = 0;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            curNodeChilds += dfs(i);
        }
    }
    curNodeChilds ++;
    if(curNodeChilds % 2) {
        return curNodeChilds;
    }
    else {
        ans ++;
        curNodeChilds = 0;
        return curNodeChilds;
    }
}

int main() {
    ll n , m;
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ans = 0;
    if(n % 2) {
        cout << ans << endl;
    }
    else{
        ll DFS = dfs(1);
        cout << ans - 1 << endl;
    }
    return 0;
}

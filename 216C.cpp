#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , found;
vector <ll> ans;
vector <ll> graph[100001];
ll visited[100001];
ll degree[100001];
ll parent[100001];
ll valueInNode[100001];
map <pair <ll , ll> , ll> mp;
ll root , repaired;

void bfs(ll start) {
    visited[start] = 1;
    queue <ll> q;
    q.emplace(start);
    while(!q.empty()) {
        ll p = q.front();
        q.pop();
        for(auto i : graph[p]) {
            if(!visited[i]) {
                ll uu = p;
                ll vv = i;
                if(mp[{uu , vv}] == 2) {
                    valueInNode[vv] += (valueInNode[p] + 1);
                }
                q.emplace(i);
                visited[i] = 1;
            }
        }
    }
}

void makeParent(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            parent[i] = start;
            makeParent(i);
        }
    }
}

void LeaftoRoot(ll start) {
    ll l = start;
    ll p = parent[l];
    if(l == root) {
        return;
    }
    if(visited[l]) {
        return;
    }
    visited[l] = 1;
    if(mp[{l , p}] == 2) {
        repaired = 1;
        mp[{l , p}] == 1;
        mp[{p , l}] == 1;
    }
    LeaftoRoot(p);
}

bool sortBySec(pair <ll , ll> a , pair <ll , ll> b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    memset(visited , 0 , sizeof(visited));
    memset(degree , 0 , sizeof(degree));
    memset(valueInNode , 0 , sizeof(valueInNode));
    memset(parent , 0 , sizeof(parent));

    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v , x;
        cin >> u >> v >> x;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;
        mp[{u , v}] = x;
        mp[{v , u}] = x;
    }

    bfs(1);

    root = 1;
    parent[root] = root;

    memset(visited , 0 , sizeof(visited));
    makeParent(1);

    vector <pair <ll , ll>> leaf;
    for(ll i = 1 ; i <= n ; i++) {
        if(degree[i] == 1) {
            leaf.push_back(make_pair(i , valueInNode[i]));
        }
    }

    sort(leaf.begin() , leaf.end() , sortBySec);
    memset(visited , 0 , sizeof(visited));
    for(auto i : leaf) {
        repaired = 0;
        visited[root] = 0;
        LeaftoRoot(i.first);
        if(repaired) {
            ans.push_back(i.first);
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

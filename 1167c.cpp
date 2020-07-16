#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , m;
ll parent[500001];
ll visited[500001];
vector <vector <ll> > v(500001);
vector <ll> graph[500001];
ll setParent;
unordered_map <ll , ll> freq;

void make_Set() {
    for(ll i = 1 ; i <= n ; i++) {
        parent[i] = 1;
    }
}

void dfs(ll start) {
    visited[start] = 1;
    parent[start] = setParent;
    freq[setParent] ++;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}


int main() {
    cin >> n >> m;
    for(ll i = 1 ; i <= m ; i++) {
        ll k;
        cin >> k;
        for(ll j = 0 ; j < k ; j++) {
            ll x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    for(ll i = 1 ; i <= m ; i++) {
        for(ll j = 1 ; j < v[i].size() ; j++) {
            ll x = v[i][j];
            ll y = v[i][j - 1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }
    memset(visited , 0 , sizeof(visited));
    memset(parent , 0 , sizeof(parent));

    make_Set();

    set <ll> s;
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            setParent = i;
            dfs(i);
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        cout << freq[parent[i]] << " ";
    }
    cout << endl;
    return 0;
}

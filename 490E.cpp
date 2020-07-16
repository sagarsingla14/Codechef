#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m , s;
vector <ll> graph[5001];
ll visited[5001] = {0};
ll used[5001] = {0};
ll cnt = 0;

void dfs(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

void dfs2(ll start) {
    used[start] = 1;
    cnt ++;
    for(auto i : graph[start]) {
        if(!visited[i] && !used[i]) {
            dfs2(i);
        }
    }
}

bool sortBySec(pair <ll , ll> a , pair <ll , ll> b) {
    return a.second > b.second;
}

int main() {
    cin  >> n >> m >> s;

    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    dfs(s);

    vector <pair <ll , ll> > v;
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            cnt = 0;
            memset(used , 0 , sizeof(used));
            dfs2(i);
            v.push_back({i , cnt});
        }
    }

    ll ans = 0;
    sort(v.begin() , v.end() , sortBySec);
    for(auto i : v) {
        if(!visited[i.first]) {
            dfs(i.first);
            ans ++;
        }
    }

    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m;
vector <ll> graph[1001];
vector <ll> cur;
vector <pair <ll , ll>> comp;
vector <pair <ll , ll>> ans;
ll dist[1001] = {0};
ll visited[1001] = {0};

void input() {
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i ++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(ll i = 0 ; i < 1001 ; i++) {
        dist[i] = 1e10;
    }
}

ll bfs(ll x) {
    cur.clear();
    queue <ll> q;
    dist[x] = 0;
    q.push(x);
    ll last;
    while(!q.empty()) {
        last = q.front();
        cur.push_back(last);
        visited[last] = 1;
        q.pop();
        for(auto i : graph[last]) {
            if(dist[i] > dist[last] + 1) {
                dist[i] = dist[last] + 1;
                q.push(i);
            }
        }
    }
    return last;
}

void calcComp() {
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            ll x = bfs(i);
            for(auto itr : cur) {
                dist[itr] = 1e10;
            }

            ll y = bfs(x);
            for(auto itr : cur) {
                dist[itr] = 1e10;
            }

            x = bfs(y);
            ll diameter = dist[x];

            for(auto itr : cur) {
                if(dist[itr] == (diameter / 2)) {
                    comp.push_back({itr , diameter});
                    break;
                }
            }
        }
    }
}

bool sortBySec(pair <ll , ll> a , pair <ll , ll> b) {
    return (a.second < b.second);
}

void printAns(ll diameter) {
    cout << diameter << endl;
    for(auto i : ans) {
        cout << i.first << " " << i.second << endl;
    }
}

void setDist() {
    for(ll i = 0 ; i < 1001 ; i++) {
        dist[i] = 1e10;
    }
}

void solve() {
    sort(comp.begin() , comp.end() , sortBySec);
    ll uCenter = comp[comp.size() - 1].first;
    ll uDiameter = comp[comp.size() - 1].second;

    for(ll i = 0 ; i < comp.size() - 1 ; i++) {
        graph[comp[i].first].push_back(uCenter);
        graph[uCenter].push_back(comp[i].first);
        ans.push_back({uCenter , comp[i].first});
    }

    setDist();
    ll x = bfs(uCenter);
    setDist();

    ll y = bfs(x);
    ll diameter = dist[y];
    printAns(diameter);
}

int main() {
    fast_io
    input();

    calcComp();
    solve();

    return 0;
}

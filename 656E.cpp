#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m;
vector <ll> v;
vector <pair <ll , ll>> edges;
vector <ll> graph[200001];
ll visited[200001] = {0};

void clearAll() {
    v.clear();
    edges.clear();
    for(ll i = 0 ; i <= n ; i++) {
        graph[i].clear();
    }
    memset(visited , 0 , sizeof(visited));
}

void topo(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            topo(i);
        }
    }
    v.push_back(start);
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        clearAll();

        for(ll i = 0 ; i < m ; i++) {
            ll q , u , v;
            cin >> q >> u >> v;
            if(q) {
                graph[u].push_back(v);
            }
            edges.push_back({u , v});
        }

        memset(visited , 0 , sizeof(visited));
        for(ll i = 1 ; i <= n ; i++) {
            if(!visited[i]) {
                topo(i);
            }
        }

        reverse(v.begin() , v.end());

        ll pos[n + 1] = {0};
        for(ll i = 0 ; i < v.size() ; i++) {
            pos[v[i]] = i;
        }

        ll cycle = 0;
        for(ll i = 1 ; i <= n ; i++) {
            for(auto j : graph[i]) {
                if(pos[i] > pos[j]) {
                    cycle = 1;
                    break;
                }
            }
        }

        if(cycle) {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(auto i : edges) {
                ll a = i.first;
                ll b = i.second;
                if(pos[b] > pos[a]) {
                    cout << a << " " << b << endl;
                }
                else{
                    cout << b << " " << a << endl;
                }
            }
        }
    }
    return 0;
}

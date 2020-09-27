#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// CYCLE DETECTION IN GRAPH USING DSU (ONLY IN CASE OF UNDIRECTED GRAPH)
ll parent[100001];
ll rnk[100001];
ll cycle;
void make_DSU(ll n) {
    for(ll i = 1 ; i <= n; i++) {
        parent[i] = i;
    }
}

ll find(ll x) {
    if(parent[x] == x) {
        return x;
    }
    else{
        ll rep = find(parent[x]);
        return rep;
    }
}

void Union(ll x , ll y) {
    ll xrep = find(x);
    ll yrep = find(y);
    if(xrep == yrep) {
        cycle = 1;
    }
    else{
        if(rnk[xrep] > rnk[yrep]) {
            parent[yrep] = xrep;
        }
        else if(rnk[xrep] < rnk[yrep]) {
            parent[xrep] = yrep;
        }
        else{
            parent[yrep] = xrep;
            rnk[xrep] ++;
        }
    }
}


int main() {
    ll n , e;
    cin >> n >> e;
    cycle = 0;
    memset(rnk , 0 , sizeof(rnk));
    memset(parent , 0 , sizeof(parent));
    make_DSU(n);
    for(ll i = 0 ; i < e ; i++) {
        ll u , v;
        cin >> u >> v;
        Union(u , v);
    }

    if(cycle) {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}

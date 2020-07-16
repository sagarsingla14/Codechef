#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll parent[150001] = {0};
ll Rank[150001] = {0};

void make_parent() {
    for(ll i = 1 ; i <= 150001 ; i++) {
        parent[i] = i;
    }
}

ll find(ll x) {
    if(parent[x] == x) {
        return parent[x];
    }
    else{
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void U(ll x , ll y) {
    ll xrep = find(x);
    ll yrep = find(y);
    if(xrep == yrep) {
        return ;
    }
    else{
        if(Rank[xrep] > Rank[yrep]) {
            parent[yrep] = xrep;
        }
        else if(Rank[xrep] < Rank[yrep]) {
            parent[xrep] = yrep;
        }
        else {
            parent[yrep] = xrep;
            Rank[xrep] ++;
        }
    }
}

int main() {
    fast_io
    ll n;
    cin >> n;
    make_parent();
    for(ll i = 0 ; i < n ; i++) {
        ll u , v;
        cin >> u >> v;
        U(u , v);
    }

    for(ll i = 1 ; i <= 2 * n ; i++) {
        parent[i] = find(parent[i]);
    }

    map <ll , ll> mp;
    for(ll i = 1 ; i <= 2 * n ; i++) {
        mp[parent[i]] ++;
    }

    ll mn = INT_MAX;
    ll mx = 0;
    for(auto i : mp) {
        if(i.second != 1) {
            mn = min(mn , i.second);
            mx = max(mx , i.second);
        }
    }
    cout << mn << " " << mx << endl;
    return 0;
}

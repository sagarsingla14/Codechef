#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll parent[100001] = {0};
ll Rank[100001] = {0};
map <ll , ll> mp;
ll ans = 0;

void make_parent() {
    for(ll i = 1 ; i <= 100000 ; i++) {
        parent[i] = i;
        mp[i] = 1;
    }
}

ll find(ll x) {
    if(x == parent[x]) {
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
        return;
    }
    else{
        if(Rank[xrep] > Rank[yrep]) {
            parent[yrep] = xrep;
            
            mp[xrep] += mp[yrep];
            mp[yrep] = 0;
        }
        else if(Rank[xrep] < Rank[yrep]) {
            parent[xrep] = yrep;
            mp[yrep] += mp[xrep];
            mp[xrep] = 0;
        }
        else{
            parent[yrep] = xrep;
            Rank[xrep] ++;
            mp[xrep] += mp[yrep];
            mp[yrep] = 0;
        }
    }
}

void query(ll x) {
    ll xrep = find(x);
    ans = mp[xrep];
}

int main() {
    ll n , m;
    cin >> n >> m;
    make_parent();
    for(ll i = 0 ; i < m ; i++) {
        char c;
        cin >> c;
        if(c == 'M') {
            ll u , v;
            cin >> u >> v;
            U(u , v);
        }
        else{
            ll x;
            cin >> x;
            ans = 0;
            query(x);
            cout << ans << endl;
        }
    }
    return 0;
}

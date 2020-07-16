#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

bool cycle;
vector <ll> graph[200010];
vector <ll> degree(200010) , visited(200010);
ll size;

ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll p = power(x , y / 2) % mod;
    p *= p;
    p %= mod;
    if(y % 2 == 1) {
        p *= x;
        p %= mod;
    }
    return p % mod;
}



void dfs(ll start) {

    visited[start] = 1;
    size ++;

    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    ll n , k;
    cin >> n >> k;

    for(ll i = 0 ; i < n - 1 ; i++ ){
        ll u , v , color;
        cin >> u >> v >> color;
        u -- , v --;
        if(color == 0) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    ll ans = power(n , k);;
    for(ll i = 0 ; i < n ; i++) {
        if(!visited[i]) {
            size = 0;
            dfs(i);
            ans -= power(size , k);
            ans += mod;
            ans %= mod;
        }
    }

    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m;
vector <ll> graph[100001];



int main() {
    cin >> n >> m;
    ll color[n + 1] = {0};

    ll check[100001] = {0};
    for(ll i = 1 ; i <= n ; i++) {
        cin >> color[i];
        check[color[i]] = 1;
    }

    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        if(color[u] != color[v]) {
            graph[color[u]].push_back(color[v]);
            graph[color[v]].push_back(color[u]);
            check[color[v]] = 0;
            check[color[u]] = 0;
        }
    }

    ll mx = 0;
    for(ll i = 0 ; i <= 100000 ; i++) {
        ll s = graph[i].size();
        mx = max(mx , s);
    }

    ll ans = 0;
    for(ll i = 0 ; i <= 100000 ; i++) {
        if(mx == graph[i].size()) {
            ans = i;
            break;
        }
    }

    if(ans) {
        cout << ans << endl;
    }
    else {
        for(ll i = 1 ; i <= 100000 ; i++) {
            if(check[i]) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353

int main() {
    ll n;
    cin >> n;
    ll degree[n + 1] = {0};
    for(ll i = 0 ; i < n - 1 ; i ++) {
        ll u , v;
        cin >> u >> v;
        degree[u] ++;
        degree[v] ++;
    }
    ll ans = 1;
    for(ll i = 1; i <= n ; i++) {
        if(degree[i] == 2) {
            ans = 0;
            break;
        }
    }
    if(!ans) {
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return 0;
}

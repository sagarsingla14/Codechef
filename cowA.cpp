#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007

int main() {

    ll n;
    cin >> n;
    map <ll , ll> start;
    map <ll , ll> end;
    ll mx = -10000000 , mn = 100000000;
    for(ll i = 0 ; i < n ; i++) {
        ll u , v;
        cin >> u >> v;
        start[u] ++;
        end[v] ++;
        mn = min(mn , u);
        mx = max(mx , v);
    }

    ll sum = 0;
    ll present = 0;
    for(ll i = mn ; i <= mx ; i++) {
        ll s = start[i];
        ll e = end[i];
        present += s;
        sum += (present % mod);
        sum %= mod;
        present -= e;
    }

    cout << sum << endl;
    return 0;
}

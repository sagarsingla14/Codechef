#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1ll;
    while(y) {
        if (y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;

    ll mn = 1e9;
    ll mx = 0;

    vector <pair <ll , ll>> v;
    for(ll i = 0 ; i < n ; i++) {
        ll x , y;
        cin >> x >> y;
        v.push_back({x , y});
        mx = max(mx , x);
        mn = min(mn , y);
    }

    sort(v.begin() , v.end());

    mn = 1e9;
    mx = 0;
    vector <pair <ll , ll>> lft(n);
    vector<pair <ll , ll>> rght(n);

    for(ll i = 0 ; i < n ; i++) {
        ll l = v[i].first;
        ll r = v[i].second;
        mx = max(mx , l);
        mn = min(mn , r);
        lft[i] = {mx , mn};
    }

    mn = 1e18;
    mx = -1;

    for(ll i = n - 1 ; i >= 0 ; i--) {
        ll l = v[i].first;
        ll r = v[i].second;
        mx = max(mx , l);
        mn = min(mn , r);
        rght[i] = {mx , mn};
    }

    ll ans = 0;
    ans = max(ans , lft[n - 2].second - lft[n - 2].first);
    ans = max(ans , rght[1].second - rght[1].first);

    for(ll i = 1 ; i < n - 1 ; i++) {
        ans = max(ans , min(lft[i - 1].second , rght[i + 1].second) - max(lft[i - 1].first, rght[i + 1].first));
    }
    cout << ans << endl;
    return 0;
}

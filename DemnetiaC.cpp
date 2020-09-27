#include <bits/stdc++.h>
using namespace std;
// #define l long long int
#define ll long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 1000000000000000000

ll calc(ll r1 , ll r2 , ll d) {
    return (r1 * r1 - r2 * r2 + d * d) / (2.0 * d);
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        map <pair <ll , ll> , ll> mp;
        vector <pair <ll , pair <ll , ll>>> v;
        for(ll i = 0 ; i < n ; i++) {
            ll x , y , r;
            cin >> x >> y >> r;
            mp[{x , y}] ++;
            v.push_back({x , {y , r}});
        }
        sort(v.begin() , v.end());

        ll ans = 0;
        for(ll i = 0 ; i < n - 1 ; i++) {
            for(ll j = i + 1 ; j < n ; j++) {
                ll x = abs(v[i].first - v[j].first);
                ll y = abs(v[i].second.first - v[j].second.first);
                x *= x , y *= y;
                ll d = sqrt(x + y);
                ll dist = calc(v[i].second.first , v[j].second.first , d);

                ll check = (v[i].second.first * v[i].second.first) / (1.0 * sqrt(2.0));
                if(check == dist) {
                    ll midx = (v[i].first + v[j].first) / 2.0;
                    ll midy = (v[i].second.first + v[j].second.first) / 2.0;
                    if(mp[{midx , midy}]) {
                        ans ++;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

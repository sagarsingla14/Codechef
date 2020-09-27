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
    ll n , x , y;
    cin >> n >> x >> y;
    ll a[n] = {0};
    ll b[n] = {0};
    vector <pair <ll , pair <ll , ll>>> v;
    for(ll i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for(ll i = 0 ; i < n ; i++) {
        cin >> b[i];
    }
    for(ll i = 0 ; i < n ; i++) {
        ll diff = b[i] - a[i];
        v.push_back({diff , {a[i] , b[i]}});
    }

    sort(v.begin() , v.end());

    ll ans = 0;
    ll i = 0;
    while(i < n && x && v[i].first <= 0) {
        ans += v[i].second.first;
        x --;
        i ++;
    }

    ll j = n - 1;
    while(j >= 0 && j >= i && y >= 0) {
        ans += v[j].second.second;
        y --;
        j --;
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }

    return res;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n , x;
        cin >> n >> x;
        ll arr[n] = {0};

        map <ll , ll> mp;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            if(arr[i] % x != 0) {
                ll rem = ((arr[i] / x) + 1) * x - arr[i];
                mp[rem] ++;
            }
        }

        ll mx = 0;
        ll val = -1;
        for(auto i : mp) {
            if(i.second >= mx && i.first != 0) {
                mx = i.second;
            }
        }

        for(auto i : mp) {
            if(i.second == mx) {
                val = max(val , i.first);
            }
        }

        if(val == -1) {
            cout << 0 << endl;
        }
        else{
            ll ans = 1 + x * (mx - 1) + val;
            cout << ans << endl;
        }
    }
    return 0;
}

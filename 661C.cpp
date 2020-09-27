#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 1000000000000000000

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1ll) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        map <ll , ll> orignal;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            orignal[arr[i]] ++;
        }

        ll ans = 0;
        for(ll i = 100 ; i >= 2 ; i--) {
            map <ll , ll> mp = orignal;
            ll cur = 0;
            for(auto itr : mp) {
                ll a = itr.first;
                ll diff = i - a;

                if(a == diff) {
                    cur += mp[a] / 2;
                    mp[a] -= mp[a] / 2;
                }
                else{
                    ll mn = min(mp[a] , mp[diff]);
                    cur += mn;
                    mp[a] -= mn;
                    mp[diff] -= mn;
                }
            }
            ans = max(ans , cur);
        }
        cout << ans << endl;
    }
    return 0;
}

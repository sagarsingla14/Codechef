#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

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
        string str;
        cin >> str;
        ll n = str.length();

        ll arr[n + 1] = {0};
        ll sum = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '+') {
                sum ++;
            }
            else{
                sum --;
            }
            arr[i + 1] = sum;
        }
        // for(ll i = 1 ; i <= n ; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        map <ll , ll> mp;

        for(ll i = 1 ; i <= n ; i++) {
            if(mp[arr[i]] == 0) {
                mp[arr[i]] = i;
            }
        }

        // for(auto i : mp) {
        //     cout << i.first << " " << i.second << endl;
        // }

        ll ans = 0;
        for(ll i = 0 ; i <= n ; i++) {
            ll val = -1 * i - 1;
            // cout << "val "  << val << endl;
            if(mp[val]) {
                ans += mp[val];
            }
            else{
                ans += n;
                break;
            }
        }

        cout << ans << endl;

    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


const ll p = 33;
const ll mod = 1e9 + 7;


int main() {
    fast_io
    ll t;
    cin >> t;

    ll power[100000] = {0};
    power[0] = 1;
    for(ll i = 1 ; i < 100000 ; i++) {
        power[i] = power[i - 1] % mod * p % mod;
    }

    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();
        ll hsh[n + 1] = {0};

        for(ll i = 0 ; i < n ; i++) {
            hsh[i + 1] = hsh[i] + (power[i] % mod * (str[i] - 'a' + 1) % mod);
            hsh[i + 1] %= mod;
        }

        ll ans = 0;
        map <ll , ll> mp;

        for(ll i = 2 ; i <= n - 2 ; i += 2) {
            ll hsh1 = (hsh[i / 2] - hsh[0] + mod) % mod;
            ll hsh2 = (hsh[i] - hsh[i / 2] + mod) % mod;
            hsh1 %= mod;
            hsh2 %= mod;

            hsh1 *= power[n - 1];
            hsh2 *= power[n - 1 - i / 2];
            hsh1 %= mod;
            hsh2 %= mod;

            if(hsh1 == hsh2) {
                mp[i] = 1;
            }
        }

        reverse(str.begin() , str.end());
        memset(hsh , 0 , sizeof(hsh));

        for(ll i = 0 ; i < n ; i++) {
            hsh[i + 1] = hsh[i] + (power[i] % mod * (str[i] - 'a' + 1) % mod);
            hsh[i + 1] %= mod;
        }

        for(ll i = 2 ; i <= n - 2 ; i += 2) {
            ll hsh1 = (hsh[i / 2] - hsh[0] + mod) % mod;
            ll hsh2 = (hsh[i] - hsh[i / 2] + mod) % mod;

            hsh1 %= mod;
            hsh2 %= mod;

            hsh1 *= power[n - 1];
            hsh2 *= power[n - 1 - i / 2];
            hsh1 %= mod;
            hsh2 %= mod;

            if(hsh1 == hsh2) {
                if(mp[n - i]) {
                    ans ++;
                }
            }

        }
        cout << ans << endl;
    }
    return 0;
}

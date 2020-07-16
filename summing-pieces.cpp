#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll ans = 0;

ll power(ll x , ll y ) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    if(y & 1) {
        return (((pw * pw) % mod) * x) % mod;
    }
    else{
        return (pw * pw) % mod;
    }
}

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    if(n == 1) {
        cout << arr[0] << endl;
    }
    else{
        ll pw = power(2 , n) % mod;
        pw += mod;
        pw --;
        ans += pw;
        ans %= mod;
        vector <ll> v;
        v.push_back(ans);
        ll prev = v[0];
        for(ll i = 0 ; i <= n - 2 ; i++) {
            ll cur = prev + (power(2 , n - 2 - i)) % mod;
            cur %= mod;
            cur += mod;
            cur -= (power(2 , i) % mod);
            cur %= mod;
            v.push_back(cur);
            prev = cur;
        }

        ans = 0;
        ll index = 0;

        for(auto i : v) {
            ans += (i * arr[index]);
            ans %= mod;
            index ++;
        }
        cout << ans << endl;
    }
    return 0;
}

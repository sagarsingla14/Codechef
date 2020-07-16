#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 998244353
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


ll n , m , ans = 0;

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1ll;
    }

    return res % mod;
}

void solve(string a , string b) {
    ll dp[n + 1] = {0};
    for(ll i = 0 ; i < n ; i++) {
        if(b[i] == '1') {
            dp[i + 1] = 1;
        }
    }
    for(ll i = 1 ; i <= n ; i++) {
        dp[i] += dp[i - 1];
    }
    for(ll i = 0 ; i < n ; i++) {
        if(a[i] == '1') {
            ll bit = n - 1 - i;
            ll cnt = dp[i + 1];

            ans += (power(2ll , bit) % mod) * (cnt % mod);
            ans %= mod;
        }
    }
    ans %= mod;
    cout << ans << endl;
}

int main() {
    fast_io
    string a , b;
    cin >> n >> m >> a >> b;
    string s = "";
    for(ll i = 0 ; i < abs(n - m) ; i++) {
        s += '0';
    }
    if(n > m) {
        b = s + b;
    }
    else{
        a = s + a;
    }
    n = max(n , m);
    solve(a , b);

    return 0;
}

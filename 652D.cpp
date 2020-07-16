#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll dp[2000001] = {0};

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

void calc() {
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 3;

    ll sum = 5;
    for(ll i = 6 ; i <= 2000000 ; i++) {
        dp[i] = sum;
        dp[i] %= mod;
        if(i % 2) {
            dp[i] ++;
            dp[i] %= mod;
        }
        sum += dp[i];
        sum %= mod;
    }
}

int main() {
    fast_io
    calc();
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n == 100 ){
            cout <<
        }
        ll ans = ((4 % mod) * (dp[n] % mod)) % mod;
        cout << ans % mod << endl;
    }
    return 0;
}

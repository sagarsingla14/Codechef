#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll dp[101];
ll visited[101];

ll power(ll x, ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    pw %= mod;
    pw *= pw;
    pw %= mod;
    if(y % 2 == 1) {
        return (pw * x) % mod;
    }
    return pw % mod;
}

void solve() {
    for(ll i = 1 ; i <= 100 ; i++) {
        ll ans = 0;
        memset(visited , 0 , sizeof(visited));
        for(ll j = 2 ; j <= sqrt(i) ; j++) {
            for(ll p = 2 ; p <= 6 ; p ++) {
                ll pw = power(j , p);
                // if(i == 25) {
                //     cout << j << " " << p << " " << pw << " " << i % pw << endl;
                // }
                if(i % pw == 0 && visited[pw] == 0) {
                    visited[pw] = 1;
                    ans += pw;
                    ans %= mod;
                }
            }
        }
        dp[i] = dp[i - 1] + ans;
        dp[i] %= mod;
        dp[i] ++;
        cout << i << " - > " << dp[i] << endl;
    }
}



int main() {
    ll t;
    cin >> t;
    // cout << pow(5 , 2) << endl;
    memset(dp , 0 , sizeof(dp));
    solve();
    while(t--) {
        ll n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}

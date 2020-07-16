#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[50001];
void preCalc() {
    for(ll i = 1 ; i <= 50000 ; i++) {
        dp[i] = (i * (i + 1)) + (((i - 1) * i) / 2);
    }
}

int main() {
    ll t;
    cin >> t;

    preCalc();
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        while(n >= 2) {
            ll val = 0;
            for(ll i = 1 ; i <= n ; i++) {
                if(dp[i] <= n) {
                    val = dp[i];
                }
                else{
                    break;
                }
            }
            n -= val;
            ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n , m , co , dooo ;
ll dp[1001];
void solve() {
    memset(dp , 0 , sizeof(dp));
    for(ll i = co ; i <= n ; i++) {
        dp[i] = max(dp[i] , dp[i - co] + dooo);
    }
    for(ll i = 0 ; i < m ; i++) {
        ll a , b , c , d;
        cin >> a >> b >> c >> d;
        for(ll j = 0 ; j < (a / b) ; j++) {
            for(ll val = n ; val >= c ; val --) {
                dp[val] = max(dp[val] , dp[val - c] + d);
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    cin >> n >> m >> co >> dooo;
    solve();
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

ll ncr[1001][1001];
ll dp[1001];
ll arr[1001];
ll n;

void calcNCR() {
    for(ll i = 0 ; i <= 1000 ; i ++) {
        ncr[i][0] = 1;
    }
    ncr[1][1] = 1;
    for(ll i = 2 ; i <= 1000 ; i++) {
        for(ll j = 0 ; j <= i ; j++) {
            ncr[i][j] = (ncr[i - 1][ j - 1] + ncr[i - 1][j]) % mod;
        }
    }
}

void fillDp() {
    dp[0] = 1;
    dp[1] = 1;
    ll balls = arr[1];
    for(ll i = 2 ; i <= n ; i++) {
        balls += arr[i];
        dp[i] = (dp[i - 1] % mod) * (ncr[balls - 1][arr[i] - 1] % mod);
        dp[i] %= mod;
    }
}

int main() {
    memset(ncr , 0 , sizeof(ncr));
    memset(dp , 0 , sizeof(dp));
    calcNCR();

    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    fillDp();
    
    cout << dp[n] % mod << endl;
    return 0;
}

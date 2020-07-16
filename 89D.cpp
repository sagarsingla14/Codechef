#include <bits/stdc++.h>
#define ll long long int
#define mod 100000000
using namespace std;

ll ans;
ll n1 , n2 , k1 , k2;
ll dp[101][101][11][11];

void InitializeDp() {
    for(ll i = 0 ; i < 101 ; i++) {
        for(ll j = 0 ; j < 101 ; j++) {
            for(ll k = 0 ; k < 11 ; k++) {
                for(ll l = 0 ; l < 11 ; l++) {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
}

ll fillDp(ll foot , ll rider , ll footPlaced , ll riderPlaced) {
    if((foot + rider) == (n1 + n2)) {
        dp[foot][rider][footPlaced][riderPlaced] = 1;
        return dp[foot][rider][footPlaced][riderPlaced];
    }
    if(dp[foot][rider][footPlaced][riderPlaced] != -1) {
        return dp[foot][rider][footPlaced][riderPlaced];
    }

    dp[foot][rider][footPlaced][riderPlaced] = 0;
    if(foot < n1 && footPlaced < k1) {
        dp[foot][rider][footPlaced][riderPlaced] = fillDp(foot + 1 , rider , footPlaced + 1 , 0);
        dp[foot][rider][footPlaced][riderPlaced] %= mod;
    }
    if(rider < n2 && riderPlaced < k2) {
        dp[foot][rider][footPlaced][riderPlaced] += fillDp(foot , rider + 1 , 0 , riderPlaced + 1);
        dp[foot][rider][footPlaced][riderPlaced] %= mod;
    }
    return dp[foot][rider][footPlaced][riderPlaced] % mod;
}

int main() {
    cin >> n1 >> n2 >> k1 >> k2;
    InitializeDp();
    ans = fillDp(0 , 0 , 0 , 0);
    cout << ans << endl;
    return 0;
}

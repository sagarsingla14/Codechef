#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[100001][6][2];
ll ans = 0 , n;
ll arr[100001] = {0};

ll solve(ll left , ll right , ll index , ll k , ll z) {
    if(k == 0) {
        return 0;
    }

    if(left) {
        if(dp[index][z][left] != -1) {
            return dp[index][z][left];
        }
    }
    if(right) {
        if(dp[index][z][right] != -1) {
            return dp[index][z][right];
        }
    }

    if(left || z == 0 || index == 0) {
        dp[index][z][right] = solve(0 , 1 , index + 1 , k - 1 , z) + arr[index];
        return dp[index][z][right];
    }
    else {
        dp[index][z][left] = solve(1 , 0 , index - 1 , k - 1 , z - 1) + arr[index];
        dp[index][z][right] = solve(0 , 1 , index + 1 , k - 1 , z) + arr[index];
    }

    if(left) {
        return dp[index][z][left];
    }
    if(right) {
        return dp[index][z][right];
    }
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll k , z;
        cin >> n >> k >> z;
        ans = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        z = min(z , 5ll);

        if(z == 0) {
            ans = 0;
            for(ll i = 0 ; i <= k ; i++) {
                ans += arr[i];
            }
            cout << ans << endl;
        }
        else{
            ll val = arr[0];
            for(ll i = 0 ; i < n ; i++) {
                for(ll j = 0 ; j <= z ; j++) {
                    for(ll k = 0 ; k < 2 ; k++) {
                        dp[i][j][k] = -1;
                    }
                }
            }

            ll right = 1 , left = 0;
            cout << solve(left , right , 0 , k , z) << endl;
        }
    }
    return 0;
}

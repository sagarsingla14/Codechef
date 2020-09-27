#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll dp[100001][6][2];
ll ans = 0 , n;
ll arr[100001] = {0};

ll solve(ll index , ll k , ll z , ll left) {
    if(k == 0) {
        return 0;
    }
    if(dp[index][z][left] != -1) {
        return dp[index][z][left];
    }

    ll val = 0;
    if(!left && z > 0 && index > 0) {
        val = max(val , solve(index - 1 , k - 1 , z - 1 , 1) + arr[index - 1]);
    }
    val = max(val , solve(index + 1 , k - 1 , z , 0) + arr[index + 1]);
    return dp[index][z][left] = val;
}


int main() {
    fast_io
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
        else {
            memset(dp , -1 , sizeof(dp));
            cout << solve(0 , k , z , 0) + arr[0] << endl;
        }
    }
    return 0;
}

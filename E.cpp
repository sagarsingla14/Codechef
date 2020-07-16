#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[2001];

ll dp[2001];

ll solve(ll val , ll index , ll mod , ll l , ll r , ll size) {
    val %= mod;
    if(dp[val] != -1) {
        return dp[val];
    }
    if(index >= size) {
        return 0;
    }
    else {
        ll left = solve(val + arr[index] , index + 1 , mod , l , r , size);
        ll right =  solve(val + arr[index] - 1 , index + 1 , mod , l , r , size);
        dp[val] = max(dp[left] , dp[val]);
        dp[val] = max(dp[right] , dp[val]);
        if(l <= val && r >= val) {
            return max(left , right) + 1;
        }
        else{
            return max(left , right);
        }
    }
}

int main() {
    ll n , h , l , r;
    cin >> n >> h >> l >> r;
    for(ll i = 0 ; i < 2001 ; i++) {
        dp[i] = -1;
    }
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    ll ans = solve(0 , 0 , h , l , r , n);
    cout << ans + 1 << endl;
    return 0;
}

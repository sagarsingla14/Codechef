#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , l;
ll arr[31];
ll dp[31];
ll ans = 9e18;

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

void fillDp() {
    dp[0] = arr[0];
    for(ll i = 1 ; i < n ; i++) {
        dp[i] = arr[i];
        dp[i] = min(dp[i] , 2 * dp[i - 1]);
    }
}

void calcAnswer() {
    ll sum = 0;
    for(ll i = n - 1 ; i >= 0 && l > 0; i--) {
        ll need = l / (power(2 , i));
        if(need > 0) {
            sum += (need * dp[i]);
            l -= (need * power(2 , i));
        }

        ll temp = 0;
        if(l > 0) {
            temp += dp[i];
        }
        ans = min(ans , sum + temp);
    }
}

int main() {

    cin >> n >> l;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    fillDp();
    calcAnswer();

    cout << ans << endl;
    return 0;
}

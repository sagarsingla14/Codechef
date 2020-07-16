#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[2][100001];
ll n , k;
string str;

bool isAns(ll ans) {
    for(ll i = 0 ; i <= n - ans ; i++) {
        ll a = dp[0][i + ans] - dp[0][i];
        ll b = dp[1][i + ans] - dp[1][i];
        ll diff = min(ans - a , ans - b);
        if(diff <= k) {
            return true;
        }
    }
    return false;
}

void DP() {
    dp[0][0] = 0;
    dp[0][1] = 0;

    for(ll i = 1; i <= n ; i++) {
        dp[str[i - 1] - 'a'][i] ++;
    }

    for(ll j = 0 ; j < 2 ; j++) {
        for(ll i = 1 ; i <= n ; i++) {
            dp[j][i] += dp[j][i - 1];
        }
    }
}

void solve() {
    ll f = 1 , l = n , ans = 0;

    while(f <= l) {
        ll mid = (f + l) / 2;
        if(isAns(mid)) {
            f = mid + 1;
            ans = mid;
        }
        else{
            l = mid - 1;
        }
    }
    cout << ans << endl;
}


int main() {
    cin >> n >> k >> str;
    memset(dp , 0 , sizeof(dp));
    DP();
    solve();
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

ll dp[2][100001];

bool isAns(ll ans , ll n , ll k) {
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


int main() {
    ll n , k;
    string str;
    cin >> n >> k >> str;
    memset(dp , 0 , sizeof(dp));

    for(ll i = 1 ; i <= n ; i++) {
        dp[str[i - 1] - 'a'][i] ++;
    }

    for(ll j = 0 ; j < 2 ; j++) {
        for(ll i = 1 ; i <= n ; i++) {
            dp[j][i] += dp[j][i - 1];
        }
    }

    ll f = 1 , l = n , ans = 0;
    while(f <= l) {
        ll mid = (f + l) >> 1;
        if(isAns(mid , n , k)) {
            f = mid + 1;
            ans = mid;
        }
        else{
            l = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

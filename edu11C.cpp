#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n , k;
    cin >> n >> k;
    ll arr[n + 1] = {0};
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    vector <ll> dp[2];
    for(ll i = 0 ; i < 2 ; i++) {
        for(ll j = 0 ; j <= n ; j++) {
            dp[i].push_back(0);
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        dp[arr[i]][i] = 1;
    }

    for(ll i = 0 ; i < 2 ; i++) {
        for(ll j = 1 ; j <= n ; j++) {
            dp[i][j] += dp[i][j - 1];
        }
    }

    ll f = 1 , l = n , ans = 0;

    while(f <= l) {
        ll mid = (f + l) / 2;
        ll ok = 0;
        for(ll i = 0 ; i <= n - mid ; i++) {
            ll left = i;
            ll right = i + mid;
            ll zero = dp[0][right] - dp[0][left];
            if(zero <= k) {
                ok = 1;
                break;
            }
        }

        if(ok) {
            ans = mid;
            f = mid + 1;
        }
        else{
            l = mid - 1;
        }
    }
    cout << ans << endl;

    for(ll i = 0 ; i <= n - ans ; i++) {
        ll cnt = dp[0][i + ans] - dp[0][i];
        if(cnt <= k) {
            for(ll j = i + 1; j < i + 1 + ans ; j++) {
                arr[j] = 1;
            }
            break;
        }
    }
    for(ll i = 1 ; i <= n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

unordered_map <ll , ll> dp;
ll arr[500001];
ll n , r;
ll ans;

void fillDp() {
    for(ll i = 1 ; i <= n ; i++) {
        dp[arr[i]] ++;
    }
}

void solve() {
    unordered_map <ll , ll> cur;
    for(ll i = 1  ; i <= n ; i++) {
        ll b = arr[i];
        ll a = 0;
        ll c = arr[i] * r;

        if(arr[i] % r == 0) {
            a = arr[i] / r;
            dp[arr[i]] --;

            ll aFreq = cur[a];
            ll bFreq = 1;
            ll cFreq = abs(dp[c] - cur[c]);

            ans += (aFreq * bFreq * cFreq);
            dp[arr[i]] ++;
        }

        cur[arr[i]] ++;
    }
}

int main() {
    ans = 0;

    cin >> n >> r;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    fillDp();
    solve();

    cout << ans << endl;
    return 0;
}

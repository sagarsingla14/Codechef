#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 998244353
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll ans = 0;

int main() {
    ll n;
    cin >> n;
    ll arr[n + 1] = {0};
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    ll dp[n + 1] = {0};
    for(ll i = 1 ; i <= n ; i++) {
        dp[i] += dp[i - 1] + arr[i];
    }

    set <ll> s;
    s.insert(0);
    ll j = 1;
    for(ll i = 1 ; i <= n ; i++) {
        while(j <= n && s.count(dp[j]) == 0)  {
            s.insert(dp[j]);
            j ++;
        }
        ans += (j - i);
        s.erase(dp[i - 1]);
    }

    cout << ans << endl;
    return 0;
}

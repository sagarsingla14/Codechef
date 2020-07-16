#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , h;
vector <pair <ll , ll> > v;
ll ans = 0;
ll dp[200001] = {0};
ll sum[200001] = {0};


void setDp() {
    dp[0] = 0;
    for(ll i = 1 ; i < n ; i++) {
        dp[i] = v[i].first - v[i - 1].second;
    }
    for(ll i = 1 ; i < n ; i++) {
        dp[i] += dp[i - 1];
    }
}

void setSum() {
    for(ll i = 1 ; i <= n ; i++) {
        sum[i] = abs(v[i - 1].first - v[i - 1].second);
    }

    for(ll i = 1 ; i <= n ; i++) {
        sum[i] += sum[i - 1];
    }
}

void check() {
    for(ll i = 0 ; i < n ; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    for(ll i = 0 ; i <= n ; i++) {
        cout << sum[i] << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> h;

    for(ll i = 0 ; i < n ; i++) {
        ll a , b;
        cin >> a >> b;
        v.push_back({a , b});
    }

    setSum();
    setDp();
    // check();
    ll mx = 0;
    for(ll i = 0 ; i < n ; i++) {
        auto index = lower_bound(dp , dp + n , h + dp[i]) - dp;
        ll add = sum[index] - sum[i];
        cout << index << " " << add << endl;
        mx = max(mx , add);
    }

    ans = mx + h;
    cout << ans << endl;

    return 0;
}

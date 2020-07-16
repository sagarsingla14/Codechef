#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector <pair <ll , ll> > v;
        for(ll i = 0 ; i < n ; i++) {
            ll x , y;
            cin >> x >> y;
            v.push_back(make_pair(x , y));
        }
        ll current[n] = {0};
        ll temp = 0;
        current[0] = max(temp , v[0].first - v[n - 1].second);
        ll sum = current[0];
        for(ll i = 1 ; i < n ; i++) {
            current[i] = max(temp , v[i].first - v[i - 1].second);
            sum += current[i];
        }
        ll ans = 1e18;
        for(ll i = 0; i < n ; i ++) {
            ans = min(ans , sum - current[i] + v[i].first);
        }
        cout << ans << endl;
    }
    return 0;
}

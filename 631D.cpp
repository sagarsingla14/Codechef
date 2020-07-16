#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , m;
vector <ll> v;
ll ans = 0;
ll dp[33][2];

ll calcAns(ll index , ll take) {
    if(index == v.size()) {
        return 1;
    }
    if(dp[index][take] != -1) {
        return dp[index][take] % m;
    }

    ll left = calcAns(index + 1 , 0) % m;
    ll right = calcAns(index + 1 , 1) % m * v[index] % m;
    dp[index][take] = left % m + right % m;
    return dp[index][take] % m;
}


int main() {
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        v.clear();
        for(ll i = 0 ; i < 32 ; i++) {
            dp[i][0] = -1;
            dp[i][1] = -1;
        }
        ll bit = log2(n);
        v.push_back(0);
        for(ll i = 0 ; i < bit ; i++) {
            ll terms = (1ll << (i + 1)) - (1ll << i);
            v.push_back(terms);
        }
        ll lg = log2(n);
        ll last = (n - (1ll << (lg))) + 1;
        v.push_back(last);
        ans = calcAns(0 , 0) % m;
        ans += m - 1;
        ans %= m;
        cout << ans << endl;
    }
    return 0;
}

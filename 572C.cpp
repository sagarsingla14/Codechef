#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll arr[500001];
ll sum[500001];
map <pair <ll , ll> , ll> dp;
vector <ll> v;
ll n , ans;

void fillDp(ll l , ll r) {
    ll val = sum[r + 1] - sum[l];
    dp[{l , r}] = val / 10;
}

void solve() {
    for(ll i = 0 ; i < n ; i++) {
        ll l = i;
        ll r = 1;
        while(l + r - 1 < n) {
            fillDp(l , l + r - 1);
            r <<= 1;
        }
    }
}

void optimiseDp() {
    for(ll i = 1 ; i <= n ; i++) {
        sum[i] += (arr[i - 1] + sum[i - 1]);
    }
}

int main() {
    cin >> n;
    for(ll i = 0 ; i < n ; i++ ) {
        cin >> arr[i];
    }

    optimiseDp();

    solve();
    ll q;
    cin >> q;
    while(q--) {
        ll l , r;
        cin >> l >> r;
        l -- , r --;
        ans = dp[{l , r}];
        cout << ans << endl;
    }
    return 0;
 }

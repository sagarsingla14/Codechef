#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 998244353
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m , w;
ll arr[100001] = {0};

bool check(ll val) {
    ll dp[n] = {0};
    ll curSeg = 0 , moves = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(i - w >= 0) {
            curSeg -= dp[i - w];
        }
        if(val - curSeg - arr[i] > 0) {
            dp[i] = val - curSeg - arr[i];
            curSeg += dp[i];
            moves += dp[i];
        }
    }

    if(moves > m) {
        return false;
    }
    else {
        return true;
    }
}

int main() {
    fast_io
    cin >> n >> m >> w;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    ll f = 1 , l = 1e9 + 1e5;
    while(f <= l) {
        ll mid = (f + l) / 2;
        if(check(mid)) {
            ans = mid;
            f = mid + 1;
        }
        else{
            l = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}

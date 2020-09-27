#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1ll;
    while(y) {
        if (y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    ll n , d;
    cin >> n >> d;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    for(ll i = 0 ; i < n ; i++) {
        ll val = arr[i] + d;
        auto index = upper_bound(arr , arr + n , val) - arr;
        ll diff = index - i;
        diff --;
        if(diff >= 2) {
            ans += ((diff) * (diff - 1)) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}

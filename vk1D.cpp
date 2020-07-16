#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <ll> v;
ll n , k;
ll ans = 0;

int main() {
    fast_io
    cin >> n >> k;

    ll arr[10001] = {0};
    for(ll i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        arr[x] ++;
    }

    for(ll i = 0 ; i <= 10000 ; i++) {
        for(ll j = i ; j <= 10000 ; j++) {
            ll m = __builtin_popcount(i ^ j);
            if(m == k) {
                if(i == j) {
                    ans += (arr[i] * (arr[i] - 1)) / 2;
                }
                else {
                    ans += (arr[i] * arr[j]);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

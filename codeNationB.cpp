#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;
    ll arr[n + 1] = {0};

    for(ll i = 1 ; i <= n ; i ++) {
        cin >> arr[i];
    }

    vector <ll> v[n + 1];

    for(ll i = 0 ; i <= n ; i++) {
        for(ll j = 0 ; j < 32 ; j++) {
            v[i].push_back(0);
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 0 ; j < 32 ; j++) {
            if(arr[i] & (1 << j)) {
                v[i][j] = 1;
            }
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 0 ; j < 32 ; j++) {
            v[i][j] += v[i - 1][j];
        }
    }

    ll q;
    cin >> q;
    while(q--) {
        ll l , r , s , t;
        cin >> l >> r >> s >> t;
        ll ans = 0;
        for(ll i = l ; i <= r + 1 - s ; i++) {
            ll left = i - 1;
            ll right = left + s;
            ll val = 0;
            for(ll j = 0 ; j < 32 ; j++) {
                ll diff = v[right][j] - v[left][j];
                if(diff == s) {
                    val += (1 << j);
                }
            }
            if(val >= t) {
                ans  ++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

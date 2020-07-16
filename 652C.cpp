#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }

    return res;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;

        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        ll v[k] = {0};
        for(ll i = 0 ; i < k ; i++) {
            cin >> v[i];
        }

        sort(arr , arr + n);
        sort(v , v + k);

        ll mx[k] = {0};
        ll mn[k] = {0};

        ll j = n - 1;
        for(ll i = 0 ; i < k ; i++) {
            if(v[i] == 1) {
                mx[i] = arr[j];
                mn[i] = arr[j];
                j --;
                v[i] = 0;
            }
            else {
                break;
            }
        }

        for(ll i = 0 ; i < k ; i++) {
            if(v[i] != 0) {
                mx[i] = arr[j];
                j --;
                v[i] --;
            }
        }

        for(ll i = 0 ; i < k ; i++) {
            if(v[i] != 0) {
                while(v[i]) {
                    mn[i] = arr[j];
                    v[i] --;
                    j --;
                }
            }
        }

        ll sum = 0;
        for(ll i = 0 ; i < k ; i++) {
            sum += mx[i] + mn[i];
        }
        cout << sum << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll  x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        if(n == 1) {
            cout << 1 << endl;
            continue;
        }

        ll mx = 0;
        ll ok = 0;

        for(ll i = 0 ; i < n ; i++) {
            if(mx <= arr[i]) {
                mx = arr[i];
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            if(arr[i] == mx) {
                if(i == 0) {
                    if(arr[i + 1] != mx) {
                        ok = 1;
                        break;
                    }
                }
                else if(i == n - 1) {
                    if(arr[i - 1] != mx) {
                        ok = 1;
                        break;
                    }
                }
                else{
                    if(arr[i - 1] != mx || arr[i + 1] != mx) {
                        ok = 1;
                        break;
                    }
                }
            }
        }

        if(ok) {
            cout << 1 << endl;
        }
        else{
            cout << n << endl;
        }
    }
    return 0;
}

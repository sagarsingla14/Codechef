#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll a[n] = {0};
        ll b[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> a[i];
        }
        for(ll i = 0 ; i < n ; i++) {
            cin >> b[i];
        }
        ll store[3] = {0};
        ll ans = 1;
        for(ll i = 0 ; i < n ; i++) {
            if(b[i] == a[i]) {
                if(a[i] == -1) {
                    store[0] = 1;
                }
                if(a[i] == 0) {
                    store[1] = 1;
                }
                if(a[i] == 1) {
                    store[2] = 1;
                }
            }
            else{
                if(b[i] > a[i]) {
                    if(store[2] == 0) {
                        ans = 0;
                    }
                }
                else{
                    if(store[0] == 0) {
                        ans = 0;
                    }
                }
            }
            if(a[i] == -1) {
                store[0] = 1;
            }
            if(a[i] == 0) {
                store[1] = 1;
            }
            if(a[i] == 1) {
                store[2] = 1;
            }
        }

        if(ans) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

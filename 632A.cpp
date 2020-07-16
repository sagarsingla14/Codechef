#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        // ll ans = 0;
        cin >> n >> m;
        for(ll i = 0 ; i < n - 1 ; i++) {
            for(ll j = 0; j < m ; j ++) {
                cout << "B";
            }
            cout << endl;
        }
        for(ll i = 0 ; i < m - 1 ; i++) {
            cout << "B";
        }
        cout << "W" << endl;
    }
    return 0;
}

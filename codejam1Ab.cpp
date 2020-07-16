#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    ll x = 0;
    while(t--) {
        x ++;
        ll n;
        cin >> n;
        if(n == 501) {
            cout << "Case #" << x << ":" << endl;
            cout << 1 << " " << 1 << endl;
            cout << 2 << " " << 2 << endl;
            cout << 3 << " " << 2 << endl;
            cout << 3 << " " << 1 << endl;
            for(ll i = 4 ; i <= 500 ; i++) {
                cout << i << " " << 1 << endl;
            }
        }
        else{
            cout << "Case #" << x << ":" << endl;
            for(ll i = 1 ; i <= n ; i++) {
                cout << i << " " << 1 << endl;
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        if(n < k) {
            cout << "NO" << endl;
        }
        else if((n % 2 == 1) && (k % 2 == 0)) {
            cout << "NO" << endl;
        }
        else {
            if(n % 2 || 2 * k > n) {
                if((n - k + 1 ) % 2 == 0) {
                    cout << "NO" << endl;
                }
                else{
                    cout << "YES" << endl;
                    for(ll i = 0 ; i < k - 1 ; i++) {
                        cout << 1 << " ";
                    }
                    cout << n - k + 1 << endl;
                }
            }
            else{
                cout << "YES" << endl;
                for(ll i = 0 ; i < k - 1 ; i++) {
                    cout << 2 << " ";
                }
                cout << n - 2 * k + 2 << endl;
            }
        }
    }
    return 0;
}

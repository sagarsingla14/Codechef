#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n == 1) {
            cout << -1 << endl;
        }
        else{
            if(n == 2) {
                cout << 23 << endl;
            }
            else{
                cout << 5 ;
                for(ll i = 0; i < n - 1 ; i++) {
                    cout << 3 ;
                }
                cout << endl;
            }
        }
    }
    return 0;
}

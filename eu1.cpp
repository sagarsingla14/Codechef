#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n % 2) {
            ll diff = n - 3;
            ll p = diff / 2;
            cout << "7";
            for(ll i = 0 ; i < p ; i++) {
                cout << "1";
            }
            cout << endl;
        }
        else{
            ll p = n / 2;
            for(ll i = 0 ; i < p ; i++) {
                cout << "1";
            }
            cout << endl;
        }
    }
    return 0;
}

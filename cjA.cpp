#include <bits/stdc++.h>
#define ll long long int
// #define mod 1000000000
using namespace std;

ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2) % mod;
    if(y & 1) {
        return (((pw * pw) % mod) * x) % mod;
    }
    return (pw * pw) % mod;
}

int main() {
    ll t;
    cin >> t;
    ll c = 1;
    while(t--) {
        ll x , y;
        cin >> x >> y;
        if(x == 0 && y == 0) {
            cout << "" << endl;
        }
        else if(x == 0 && y == 1) {
            
        }
    }
    return 0;
}

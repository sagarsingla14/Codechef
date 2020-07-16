#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    if(y & 1) {
        return pw * pw * x;
    }
    return pw * pw;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        while(n) {
            if(n == power(2 , log2(n))) {
                n >>= 1;
            }
            else{
                ll temp = power(2 , log2(n));
                n -= temp;
            }
            ans ++;
            if(n == 1) {
                break;
            }
        }

        if(ans & 1) {
            cout << "Louise" << endl;
        }
        else {
            cout << "Richard" << endl;
        }
    }
    return 0;
}

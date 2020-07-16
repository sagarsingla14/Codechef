#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fast_power(ll base, ll power) {
    long long result = 1;
    while(power > 0) {

        if(power & 1) {
            result = (result*base) ;
        }
        base = (base * base) ;
        power = power >>= 1;
    }
    return result ;
}

int main() {
    ll t;
    cin >> t;

    while(t--){
        ll n,d;
        cin >> n >> d;

        if(n >= d){
            cout << "YES" << endl;
            continue;
        }

        ll dis = fast_power((1-n),2) - 4 * (d-n);
        if(dis >= 0){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
    return 0;
}

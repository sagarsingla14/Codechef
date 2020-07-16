#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main() {
    ll t;
    cin >> t;
    while (t--) {
//         999999000000
// 1e+006
        // ll n , x;
        // cin >> n >> x;
        // ll y = n / (x + 1) + 1;
        // ll z = n / x;
        // cout << y << " " << z << endl;
        // cout << n / y << endl;
        // cout << "diff " << z - y << endl;
        // cout <<" ------ " << endl;
        for(ll i = sqrt(n) ; i >= 1000001 ; i++) {
            cout << i << " " << n / i << endl;
        }
    }
    return 0;
}

// 10000000000000 1020001

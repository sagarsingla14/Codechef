#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , a , b , c , d , e , i;
        cin >> n;
        cin >> a;
        ll p = pow(10 , n);
        ll sum = 2 * p + a;
        cout << sum << endl << flush;
        cin >> b;
        c = p - b;
        cout << c << endl << flush;
        cin >> d;
        cout << sum - a - b - c - d << endl << flush;
        cin >> i;
        if(i == -1) {
            return 0;
        }
    }
}

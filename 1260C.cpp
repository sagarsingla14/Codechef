#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main () {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b , c;
        cin >> a >> b >> c;
        ll mx = max(a , b);
        ll mn = min(a , b);
        ll gcd = __gcd(a , b);
        mx /= gcd;
        mn /= gcd;
        mx--;
        ll val = mx / mn;
        if(mx % mn) {
            val++;
        }
        // cout << val << endl;
        if(val >= c) {
            cout << "REBEL" << endl;
        }
        else{
            cout << "OBEY" << endl;
        }
    }
    return 0;
}

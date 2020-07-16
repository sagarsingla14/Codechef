#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd(ll a , ll b) {
    if(b == 0) {
        return a;
    }
    return gcd(b , a % b);
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b;
        cin >> a >> b;
        ll mx = max(a , b);
        ll mn = min(a , b);
        ll g = gcd(mx , mn) > 0 ? gcd(mx , mn) : -1 * gcd(mx , mn);
        cout << g << " " << (a / g) * b << endl;
    }
    return 0;
}

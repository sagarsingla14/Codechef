#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll r,c, dr, dc;
        cin >> r >> c >> dr >> dc;
        dr ++;
        dc ++;
        ll a = (abs(dr - 1) * c);
        ll b = (abs(r - dr) * c);
        ll x = (abs(dc - 1) * r);
        ll d = (abs(c - dc) * r);
        ll mx = max(a , b);
        mx = max(mx , x);
        mx = max(mx , d);
        cout << mx << endl;
    }
    return 0;
}

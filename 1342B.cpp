#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll x , y , a , b;
        cin >> x >> y >> a >> b;
        if(b <= 2 * a) {
            ll mn = min(x , y);
            x -= mn ;
            y -= mn;
            ll ans = mn * b;
            ans += (x + y) * a;
            cout << ans << endl;
        }
        else{
            ll ans = a * (x + y);
            cout << ans << endl;
        }
    }
    return 0;
}

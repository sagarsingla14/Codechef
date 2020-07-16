#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll x1 , x2 , y1 , y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = (x2 - x1) * (y2 - y1) + 1;

        cout << ans << endl;
    }
    return 0;
}

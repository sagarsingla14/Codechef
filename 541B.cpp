#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , ans , x , y;

int main() {
    cin >> n;
    ans = 1;
    ll px = 0 , py = 0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> x >> y;
        ans += max(0ll , min(x , y) - max(px , py) + 1 - (px == py));
        px = x;
        py = y;
    }
    cout << ans << endl;
    return 0;
}

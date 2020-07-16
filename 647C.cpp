#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = 0;
        ans += (n + 1) / 2;

        for(ll i = 1 ; i <= 61 ; i++) {
            ll terms = (n + (1ll << i)) / (1ll << (i + 1));
            ans += (terms * (i + 1));
        }
        cout << ans << endl;
    }
    return 0;
}

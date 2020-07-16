#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;

        if(x == 2) {
            cout << -1 << endl;
            continue;
        }
        if(x % 4 == 0 || x % 4 == 2) {
            cout << x / 4 << endl;
        }
        else if(x % 4 == 1) {
            if((x / 4) >= 2) {
                ll ans = (x / 4) - 1;
                if(ans) {
                    cout << ans << endl;
                }
                else {
                    cout << -1 << endl;
                }
            }
            else {
                cout << -1 << endl;
            }
        }
        else {
            if((x / 4) >= 2) {
                ll ans = (x / 4) - 1;
                if(ans - 1) {
                    cout << ans << endl;
                }
                else {
                    cout << -1 << endl;
                }
            }
            else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}

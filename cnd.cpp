#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n , m;
    cin >> n >> m;
    vector <string> v;
    for (ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    ll ans = 0;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll val = 0;
            for (ll k = 0; k < m; k++) {
                if (v[i][k] == '1') {
                    val++;
                }
                else if(v[j][k] == '1') {
                    val++;
                }
            }
            if (ans == val) {
                cnt++;
            }
            else if (ans < val) {
                ans = val;
                cnt = 1;
            }
        }
    }
    cout << ans << endl;
    cout << cnt << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll m , n ;
        cin >> m >> n;
        for(ll i = 0 ; i < m ; i++) {
            string str;
            cin >> str;
        }
        ll s[n] = {0};
        ll p[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> s[i];
        }
        for(ll i = 0 ; i < n ; i++) {
            cin >> p[i];
        }
        cout << n << endl;
        for(ll i = 0 ; i < n ; i++) {
            cout << 1 << " " << s[i] << " " << i + 1 << endl;
        }
    }
    return 0;
}

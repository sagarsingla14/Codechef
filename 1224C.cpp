#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll reached(ll val , string str) {
    ll
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll l = str.length();
        ll f = 0 ; l = l;
        ll ans = INT_MAX;
        while(f <= l) {
            ll mid = (f + l) / 2;
            ll check = reached(mid , str);
            if(check) {
                l = mid - 1;
                ans = min(check , ans);
            }
            else{
                f = mid + 1;
            }
        }

        cout << ans << endl;
    }
}

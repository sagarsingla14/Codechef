#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string a , b;
        cin >> a >> b;

        ll la = a.length();
        ll lb = b.length();

        if(lb < la) {
            ll diff = abs(lb - la);
            string s = "";
            for(ll i = 0 ; i < diff ; i++) {
                s += '0';
            }
            b = s + b;
        }

        ll n = la;
        ll index = la - 1;
        for(ll i = la - 1 ; i >= 0 ; i --) {
            if(b[i] == '1') {
                index = i;
                break;
            }
        }

        ll ans = 0;
        for(ll i = index ; i >= 0 ; i--) {
            if(a[i] != '1') {
                ans ++;
            }
            else {
                break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

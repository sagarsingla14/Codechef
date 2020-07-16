#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b , c;
        cin >> a >> b >> c;
        ll ans = INT_MAX;
        ll aa = -1;
        ll bb = -1;
        ll ccc = -1;
        for(ll i = 1 ; i <= 2 * a ; i++) {
            for(ll j = i ; j <= 2 * b ; j += i) {
                ll temp = INT_MAX;
                if(j % i == 0) {
                    ll cf = (c / j) * j;
                    ll cc = (c / j) * j + j;
                    temp = abs(a - i) + abs(b - j) + min(abs(c - cc) , abs(c - cf));
                    ans = min(ans , temp);
                    if(ans == temp) {
                        aa = i;
                        bb = j;
                        ll dcc = abs(c - cc);
                        ll dcf = abs(c - cf);
                        if(dcc > dcf) {
                            if(cf >= j) {
                                ccc = cf;
                            }
                            else{
                                ccc = cc;
                            }
                        }
                        else{
                            if(cc >= j) {
                                ccc = cc;
                            }
                            else{
                                ccc = cf;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        cout << aa << " " << bb << " " << ccc << endl;
    }
    return 0;
}

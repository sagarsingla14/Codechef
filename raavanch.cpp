#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b , c , d , e;
        cin >> a >> b >> d >> e;
        ll xr = a ^ b;

        ll xrr[60] = {0};
        ll dd[60] = {0};
        ll ee[60] = {0};

        ll index = 59;
        while(e) {
            if((e & 1ll)) {
                ee[index] = 1;
            }
            e >>= 1ll;
            index --;
        }

        index = 59;
        while(d) {
            if((d & 1ll)) {
                dd[index] = 1;
            }
            d >>= 1ll;
            index --;
        }

        index = 59;
        while(xr) {
            if((xr & 1ll)) {
                xrr[index] = 1;
            }
            xr >>= 1ll;
            index --;
        }

        ll ans = 0;
        ll cnt = 0;
        for(ll i = 59 ; i >= 0 ; i--) {
            if(dd[i] == 0 && ee[i] == 0 && xrr[i] == 0) {
                ans += (1ll << cnt);
            }
            cnt ++;
        }
        cout << ans << endl;
    }
    return 0;
}

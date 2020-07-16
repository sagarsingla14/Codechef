#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n , t;
    cin >> t;
    while(t--) {
        cin >> n;
        ll arr[8] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19};

        ll ans = 0;
        for(ll i = 1 ; i <= 255 ; i++) {
            ll num = 1;
            ll cnt = 0;
            for(ll j = 0 ; j < 8 ; j++) {
                if((i & (1ll << j))) {
                    num *= arr[j];
                    cnt ++;
                }
            }

            if(cnt & 1) {
                ans += (n / num);
            }
            else{
                ans -= (n / num);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

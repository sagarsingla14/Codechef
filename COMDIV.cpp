#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

int main() {
    fast_io
    ll t;
    scanf("%d", &t);
    while(t--) {
        ll x , y;
        scanf("%d", &x);
        scanf("%d", &y);

        x = __gcd(x , y);
        ll ans = 1;
        for(ll i = 2 ; i * i <= x ; i++) {
            if(x % i == 0) {
                ll cnt = 0;
                while(x % i == 0) {
                    cnt ++;
                    x /= i;
                }
                cnt ++;
                ans *= cnt;
            }
        }
        if(x > 1) {
            ans *= 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}

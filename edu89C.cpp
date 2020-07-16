#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , x , m;
        cin >> n >> x >> m;

        ll mn = -1 , mx = -1;
        ll ans = 0;
        ll flag = 0;

        for(ll i = 0 ; i < m ; i++) {
            ll a , b;
            cin >> a >> b;
            if(a <= x && b >= x && flag == 0) {
                flag = 1;
                mn = a;
                mx = b;
            }
            if(flag) {
                if(b >= mn && b <= mx) {
                    mn = min(mn , a);
                    mx = max(mx , b);
                }
                if(a >= mn && a <= mx) {
                    mn = min(mn , a);
                    mx = max(mx , b);
                }
                if(a <= mn && b >= mx) {
                    mn = min(mn , a);
                    mx = max(mx , b);
                }
            }
        }

        ans = (mx - mn + 1);
        cout << ans << endl;
    }
    return 0;
}

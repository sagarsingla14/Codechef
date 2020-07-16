#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b , n;
        cin >> a >> b >> n;

        ll mx = max(a , b);
        ll mn = min(a , b);\

        ll cnt = 0;
        while(mx <= n && mn <= n) {
            cnt ++;
            if(cnt % 2) {
                mn += mx;
            }
            else{
                mx += mn;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}

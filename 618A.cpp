#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n ;
        cin >> n;

        ll sum = 0 , cnt = 0;
        for(ll i = 0 ; i < n ; i++) {
            ll x ;
            cin >> x;
            sum += x;
            if(!x) {
                cnt ++;
            }
        }

        if(!(sum + cnt)) {
            cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}

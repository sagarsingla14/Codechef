#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);\

    ll n , k;
    cin >> n >> k;
    ll mask[16] = {0};
    for(ll i = 0 ; i < n ; i++) {
        ll num = 0;
        for(ll j = 0 ; j < k ; j ++ ) {
            ll x;
            cin >> x;
            if(x) {
                num += (x << j);
            }
        }
        mask[num] ++;
    }

    ll ans = 0;
    for(ll i = 0 ; i < 15 ; i++) {
        for(ll j = 0 ; j < 15 ; j ++) {
            if(mask[i] && mask[j]) {
                if((i & j) == 0) {
                    ans = 1;
                    break;
                }
            }
        }
        if(ans) {
            break;
        }
    }

    if(ans) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}

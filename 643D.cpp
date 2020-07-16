#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll a , b , c , d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    if(a == d) {
        cout << 1 << endl;
        return 0;
    }
    for(ll i = c ; i < b + c ; i++) {
        ll flag = 0;
        for(ll j = c ; j >= b ; j--) {
            for(ll k = b ; k >= a ; k--) {
                if(i >= j + k) {
                    flag = 1;
                    break;
                }
                else{
                    ans ++;
                }
            }
            if(flag) {
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

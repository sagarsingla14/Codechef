#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        ll ans = n;
        if(n % 2) {
            ll prime = 1;
            for(ll i = 2 ; i <= sqrt(n) ; i++) {
                if(n % i == 0) {
                    ans += i;
                    prime = 0;
                    break;
                }
            }
            if(prime) {
                ans += n;
            }
            ans += 2 * (k - 1);
        }
        else {
            ans += 2 * k;
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
const ll mod = 1e9 + 7;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        if(k == 0) {
            ll sum = ((n) * (n + 1)) / 2;
            cout << sum  << endl;
        }
        else if(k == 1){
            ll sum = ((n) * (n + 1)) / 2;
            sum *= 2;
            sum --;
            sum -= n;
            cout << sum  << endl;
            
        }
        else{
            ll sum = 0;
            for(ll i = 1 ; i <= n ; i++) {
                ll mul = 1;
                for(ll j = 0 ; j <= k ; j ++) {
                    mul *= (i + j) % mod;
                    mul %= mod;
                }

                sum += mul;
                sum %= mod;
            }
            cout << sum % mod << endl;
        }

    }

    return 0;
}

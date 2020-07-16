#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        if(k >= n) {
            cout << 1 << endl;
        }
        else{

            set <ll> s;
            ll prime = 1;
            s.insert(1);
            for(ll i = 2 ; i * i <= n ; i++) {
                if(n % i == 0) {
                    s.insert(i);
                    s.insert(n / i);
                    prime = 0;
                }
            }

            if(prime) {
                cout << n << endl;
            }
            else{
                ll ans = 0;
                for(auto i : s) {
                    if(i <= k) {
                        ans = i;
                    }
                    else{
                        break;
                    }
                }
                ans = n / ans;
                cout << ans << endl;
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        if(n & 1) {
            set <ll> s;
            ll prime = 1;
            for(ll i = 2 ; i * i <= n ; i++) {
                if(n % i == 0) {
                    prime = 0;
                    s.insert(i);
                    s.insert(n / i);
                }
            }

            if(prime) {
                cout << 1 << " " << n - 1 << endl;
            }
            else{
                ll lcm = n;
                ll num = 0;
                for(auto i : s) {
                    ll a = i;
                    ll b = n - i;
                    ll g = __gcd(a , b);
                    ll l = (a *  b) / g;
                    if(lcm >= l) {
                        num = i;
                    }
                }
                cout << num << " " << n - num << endl;
            }
        }
        else {
            cout << n / 2 << " " << n / 2 << endl;
        }
    }
    return 0;
}

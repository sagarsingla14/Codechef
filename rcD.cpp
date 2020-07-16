#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll n , k;
ll t;
ll ans = 0;

ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    if(y & 1) {
        return (((pw * pw) % mod) * x) % mod;
    }
    else{
        return ((pw * pw) % mod);
    }
}

int main() {
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n >> k;
        ll tt = k - 1;
        ll val = (tt - 1) / 2;
        if(k == 1) {
            cout << power(n , 2) % mod << endl;
        }
        else if(n == 0){
            ans = (power(k - 1 ,  2) % mod);
            ans %= mod;
            ans += (k - 1);
            ans %= mod;
            cout << ans << endl;
        }
        else if((k - 1) % 2) {
            ll curans = val;
            curans = power(curans , 2) % mod;
            curans += val;
            curans %= mod;
            curans += n;
            curans %= mod;
            cout << curans << endl;
        }
        else if(((k - 1) % 2) == 0) {
            ll curans = val;
            ll net = val;
            curans = power(curans , 2) % mod;
            curans += mod;
            curans -= (n - 1);
            curans %= mod;
            curans += net;
            curans %= mod;
            curans += mod;
            curans --;
            curans %= mod;
            cout << curans << endl;
        }
    }
    return 0;
}

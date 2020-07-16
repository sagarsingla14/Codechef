#include <bits/stdc++.h>
#define mod 998244353
#define ll long long int
using namespace std;

ll power(ll a, ll b)
{
    ll res = 1;
    while (b > 0) {
        if (b & 1){
            res = (res * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    return res % mod;
}

int main() {
    ll n , m;
    cin >> n >> m;
    string a , b;
    cin >> a >> b;
    ll la = a.length();
    ll lb = b.length();

    string fb , fa;
    if(la != lb) {
        if(la > lb) {
            ll d = abs(la - lb);
            for(ll i = 0; i < d ; i++) {
                fb += '0';
            }
            fb += b;
            fa += a;
        }
        else{
            ll d = abs(la - lb);
            for(ll i = 0; i < d ; i++) {
                fa += '0';
            }
            fa += a;
            fb += b;
        }
    }
    else{
        fa = a;
        fb = b;
    }


    la = fa.length();
    lb = fb.length();
    ll one[lb] = {0};
    n = lb;

    for(ll i = 0 ; i < n; i++) {
        if(fb[i] == '1') {
            one[i] = 1;
        }
    }

    // for(ll i = 0 ; i < n ; i++) {
    //     cout << one[i] << " ";
    // }
    // cout << endl;

    for(ll i = 1 ; i < n ; i++) {
        one[i] += one[i - 1];
    }
    // for(ll i = 0 ; i < n ; i++) {
    //     cout << one[i] << " ";
    // }
    // cout << endl;
    ll ans = 0;

    ll p = 0;
    for(ll i = n - 1 ; i >= 0; i--) {
        if(fa[i] == '1') {
            ll mul = one[i];
            ll fun = power(2 , p);
            ans += ((mul % mod) * (fun % mod)) % mod;
            // cout << "i -> " << i << " p - >" << p << " mul -> " << mul << " power -> " << fun << endl;
            ans %= mod;
        }
        p++;
    }
    cout << ans % mod << endl;

    return 0;
}

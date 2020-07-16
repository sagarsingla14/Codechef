#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll gcdExtended(ll a, ll b, ll *x, ll *y);

ll modInverse(ll a, ll m) {
    ll x, y;
    ll g = gcdExtended(a, m, &x, &y);
    ll res = (x % m + m) % m;
    // cout << "Modular multiplicative inverse is " << (res * 4) % 1000000007;
    return res % mod;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    ll x1 , y1;
    ll gcd = gcdExtended(b % a , a , &x1 , &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

int main () {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string str;
        cin >> str;
        ll l = str.length();
        ll nc  = 0 , no = 0;
        ll arr[5001];
        for(ll i = 0 ; i < 5001 ; i++) {
            arr[i] = 0;
        }
        // unordered_map <ll, ll> freq;
        for(ll i = 0 ; i < l; i ++) {
            nc = 0 , no = 0;
            ll count = 0;
            for(ll j = i ; j < l ; j++) {
                if(str[j] == '(') {
                    no ++;
                }
                if(str[j] == ')') {
                    nc ++;
                }

                if(nc > no) {
                    count ++;
                    no ++;
                    nc --;
                }
                // freq[count] ++;
                arr[count] ++;
            }
        }
        ll deno = (n * (n + 1)) / 2;
        ll ans = 0;
        // unordered_map <ll , ll> :: iterator itr;
        ll modinval = modInverse(deno , mod);

        for(ll i = 1 ; i < 5001 ; i++) {
            ll m1 = i;
            ll m2 = arr[i];
            ll m = ((m1 % mod) * (m2 % mod)) % mod;
            ans += ((m % mod) * (modinval % mod)) % mod;
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}

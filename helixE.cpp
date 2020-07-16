#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353

ll n , q;
ll arr[1000000] = {0};

ll gcdExtended(ll a, ll b, ll *x, ll *y);

ll modInverse(ll b, ll m) {
    ll x, y;
    ll g = gcdExtended(b , m , &x , &y);

    if (g != 1)
        return -1;

    return (x %  m + m) % m;
}

void modDivide(ll a, ll b, ll m) {
    a = a % m;
    ll inv = modInverse(b, m);
    cout << (inv * a) % m << endl;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}


int main() {
    cin >> n >> q;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    while(q--) {
        ll x;
        cin >> x;
        ll cnt = 0;
        for(ll i = 0 ; i < n ; i++) {
            ll orr = (arr[i] | x);
            if(orr == x) {
                cnt ++;
            }
        }
        ll num = cnt;
        ll deno = n;

        ll gcd = __gcd(num , deno);

        num /= gcd;
        deno /= gcd;
        
        ll m = 998244353;
        modDivide(num , deno , m);
    }
    return 0;
}

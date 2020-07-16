#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;


ll gcdExtended(ll a, ll b, ll *x, ll *y);

ll modInverse(ll b, ll m) {
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x%m + m) % m;
}

ll modDivide(ll a, ll b, ll m) {
    a = a % m;
    ll inv = modInverse(b, m);
    return (inv * a) % m;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)  {
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2) % mod;
    if(y & 1) {
        return (((pw * pw) % mod) * x) % mod;
    }
    else{
        return (pw * pw) % mod;
    }
}

int main() {
    string str;
    cin >> str;
    ll l = str.length();
    ll index = 0;
    ll ans = 0;

    for(ll i = l - 1 ; i >= 0 ; i--) {
        ll a = abs(l - index);
        ll digit = (str[i] - '0');
        ll pw = power(10 , index + 1) % mod;
        pw --;
        pw = modDivide(pw , 9ll , mod);
        ans += ((a * digit) % mod) * (pw % mod);
        ans %= mod;
        index ++;
    }

    cout << ans % mod << endl;
    return 0;
}

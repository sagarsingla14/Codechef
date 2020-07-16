#include <bits/stdc++.h>
#define ll long long int
#define mod 998244353
using namespace std;

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
ll nCrModPFermat(ll n, ll r, ll p)
{
   // Base case
   if (r==0)
      return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n+1];
    fac[0] = 1;
    for (ll i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%p;

    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}


int main() {

    ll n , m;
    cin >> n >> m;
    ll pw = 1;
    for(ll i = 0 ; i < n - 3 ; i++) {
        pw *= 2;
        pw %= mod;
    }
    // cout << pw <<endl;
    pw %= mod;
    pw *= (n - 2);
    pw %= mod;
    ll p = 998244353;
    ll ncr = nCrModPFermat(m , n - 1 , p);

    ncr %= mod;
    cout <<  (( ncr % mod ) * (pw % mod) ) % mod << endl;
    return 0;
}

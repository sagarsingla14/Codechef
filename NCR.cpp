// Program to calculate C(n ,k)
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Returns value of Binomial Coefficient C(n, k)
ll binomialCoeff(ll n, ll k)
{
    ll res = 1;

    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;

    // Calculate value of
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (ll i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

// Driver Code

int main()
{
    ll n = 100, k = 50;
    cout << "Value of C(" << n << ", "
         << k << ") is " << binomialCoeff(n, k);
    return 0;


}

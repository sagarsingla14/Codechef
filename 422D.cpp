#include <bits/stdc++.h>
using namespace std;
#define base 1000000007
#define ll long long int
#define inf INT_MAX
vector <ll> prime(5000001);
// vector <ll> comp(5000001);
vector <ll> primeVal;
//
// ll power(ll x , ll y) {
//     ll res = 1;
//     if(y == 0) {
//         return 1;
//     }
//     if(y == 1) {
//         return x;
//     }
//     ll pw = power(x , y / 2);
//     pw %= mod;
//     if(y % 2 == 0) {
//         res = pw  * pw;
//         res %= mod;
//     }
//     else{
//         res = (pw * pw) % mod * (x % mod) ;
//         res %= mod;
//     }
//     return res % mod;
// }
// ll nction(ll n) {
//     if(prime[n]) {
//         ll val = (n)*(n - 1) / 2;
//         val %= mod;
//         return val;
//     }
// }
// ll unction(ll n) {
//     if(prime[n]) {
//         ll val = (n)*(n - 1) / 2;
//         val %= mod;
//         return val;
//     }
//     else{
//         ll primeSize = primeVal.size();
//         // cout << primeSize << endl;
//         ll ans = 0;
//         for(ll i = 0 ; i < primeSize ; i++) {
//             // cout << "div " << primeVal[i] << endl;
//             if(n == 1) {
//                 break;
//             }
//             while (n % primeVal[i] == 0) {
//                 ll mul = n / primeVal[i];
//                 ll f = primeVal[i];
//                 ll mul1 = nction(f);
//                 ans += (mul % mod) * (mul1 % mod);
//                 ans %= mod;
//                 n /= f;
//                 if(n == 1) {
//                     break;
//                 }
//             }
//         }
//         return ans % mod;
//     }
// }
//
// void sieve() {
//     ll val = sqrt(5000001);
//     for(ll i = 2 ; i <= val ; i++) {
//         if(prime[i]) {
//             for(ll j = i * i ; j < 5000001 ; j += i) {
//                 prime[j] = 0;
//             }
//         }
//     }
//
//     for(ll i = 2 ; i < 5000001 ; i++) {
//         if(prime[i]) {
//             primeVal.push_back(i);
//         }
//     }
// }

// int main() {
    const int maxn = 5000500;

int isPrime[maxn];
ll dp[maxn];

int main()
{
    int t, l, r;
    scanf ( "%d%d%d", &t, &l, &r );
    for ( int j = 2; j < maxn; j++ )
        isPrime[j] = j;
    for ( int j = 2; j * j < maxn; j++ )
        if ( isPrime[j] == j )
            for ( int i = j * j; i < maxn; i += j )
                isPrime[i] = min( j, isPrime[i] );

    for(ll i = 0 ; i < 20 ; i++) {
        cout << i << " " << isPrime[i] << endl;
    }
    cout << endl;



    dp[1] = 0;
    for ( int j = 2; j < 20; j++ ) {
        dp[j] = 1LL * inf * inf;
        for ( int x = j; x != 1; x /= isPrime[x] )
            dp[j] = min( dp[j], 1LL * dp[j / isPrime[x]] + 1LL * j * (isPrime[x] - 1 ) / 2LL );
        cout << dp[j] << " ";
    }

    int ans = 0;
    int cnt = 1;
    for ( int j = l; j <= r; j++ ) {
        dp[j] %= base;
        ans = ( 1LL * ans + 1LL * cnt * dp[j] ) % base;
        cnt = ( 1LL * cnt * t ) % base;
    }
    printf ( "%d\n", ans );
}
    // fill(prime.begin(), prime.end(), 1);
    // sieve();
    // ll t , l , r;
    // cin >> t >> l >> r;
    // ll tp = 0;
    // ll ans = 0;
    // for(ll i = l ; i <= r ; i++) {
    //     // cout << "i " << i << endl;
    //     // cout << ans << endl;
    //     ll pw = power(t , i - l);
    //     // cout << i << " " << pw << endl;
    //     pw %= mod;
    //     ll fn = unction(i);
    //     // cout << i << " " << fn << endl;
    //     fn %= mod;
    //     ans += ((pw * fn) % mod);
    //     ans %= mod;
    // }
    // cout << ans % mod << endl;
    // return 0;
// }

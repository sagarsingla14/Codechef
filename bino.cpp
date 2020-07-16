#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define mod 1000000007
using namespace std;

ll calcncr(ll n , ll r) {
    ll num = 1;
    for(ll i = 1 ; i <= n ; i++) {
        num *= i;
    }
    ll deno1 = 1;
    ll deno2 = 1;
    for(ll i = 1 ; i <= r ; i++) {
        deno1 *= i;
    }
    for(ll i = 1 ; i <= (n - r) ; i++) {
        deno2 *= i;
    }

    ll val = num / deno1;
    val /= deno2;
    return val;
}

int main() {
    ll n , r;
    cin >> n >> r;
    ll ncr = calcncr(n , r);
    ld operand = pow(2 , n);
    ld ans = ncr / 1.0;
    ans = ans / operand;
    cout << fixed << setprecision(6) << ans << endl;
    // cout << num << " " << deno << " " << operand << endl;
}

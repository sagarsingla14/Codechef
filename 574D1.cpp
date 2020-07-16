#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 998244353

ll n;
ll ans = 0 , len = 0;
string arr[100001];

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1ll;
    }
    return res % mod;
}

void calcLen(string x) {
    len = x.length();
}

void solve() {
    ll pw = 2 * len - 1;
    for(ll i = 0 ; i < 2 * len ; i += 2) {
        ll curSum = 0;

        // cout << "i " << i << "-> ";
        for(ll j = 0 ; j < n ; j ++) {
            string str = arr[j];
            // cout << str[i / 2] - '0' << " " ;
            curSum += (str[i / 2] - '0');
        }
        // cout << curSum << endl;

        ans += ((((n % mod) * (curSum % mod)) % mod) * (power(10 , (pw - 1)) % mod)) % mod;
        ans %= mod;

        ans += ((((n % mod) * (curSum % mod)) % mod) * (power(10 , pw) % mod)) % mod;
        ans %= mod;

        pw -= 2;
    }

    ans %= mod;
}

int main() {
    cin >> n;

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    calcLen(arr[0]);
    solve();
    ans %= mod;

    cout << ans << endl;
    return 0;
}

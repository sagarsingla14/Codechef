#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }

    return res;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll dp[n + 1] = {0};
        string str;
        cin >> str;
        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '(') {
                dp[i + 1] = dp[i] + 1;
            }
            else{
                dp[i + 1] = dp[i] - 1;
            }
        }

        ll mn = INT_MAX;
        for(ll i = 1 ; i <= n ; i++) {
            mn = min(mn , dp[i]);
        }

        cout << abs(mn) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1ll;
    while(y) {
        if (y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        ll mx = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mx = max(mx , arr[i]);
        }

        string str[n + 1];
        for(ll i = 0 ; i <= n ; i++) {
            string s = "";
            for(ll j = 0 ; j <= mx ; j++) {
                s += 'a';
            }
            str[i] = s;
        }

        for(ll i = 0 ; i < n ; i++) {
            ll index = arr[i];
            ll val = str[i][index];
            val ++;
            val -= 97;
            val %= 26;
            str[i + 1][index] = 'a' + val;
            for(ll j = 0 ; j < index ; j++) {
                str[i + 1][j] = str[i][j];
            }
        }

        for(ll i = 0 ; i <= n ; i++) {
            cout << str[i] << endl;
        }
    }
    return 0;
}

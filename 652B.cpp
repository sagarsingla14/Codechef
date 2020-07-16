#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

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
        string str;
        cin >> str;

        ll index = -1;
        ll one = -1;
        for(ll i = n - 1 ; i >= 0 ; i--) {
            if(str[i] == '0') {
                index = i;
                break;
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '1') {
                one = i;
                break;
            }
        }

        if(index == -1 || one == -1) {
            cout << str << endl;
            continue;
        }
        if(index < one) {
            cout << str << endl;
            continue;
        }

        string ans = "";
        for(ll i = 0 ; i < one ; i++) {
            ans += str[i];
        }

        for(ll i = index ; i < n ; i++) {
            ans += str[i];
        }

        cout << ans << endl;
    }
    return 0;
}

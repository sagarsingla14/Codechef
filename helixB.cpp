#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
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
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();
        ll ans = 0;
        for(ll i = 1 ; i < n ; i++) {
            if(str[i] == str[i - 1]) {
                ans = 1;
                break;
            }
        }

        if(ans) {
            cout << "good" << endl;
        }
        else{
            cout << "bad" << endl;
        }
    }
    return 0;
}

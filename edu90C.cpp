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
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();

        ll one = 0 , zero = 0;

        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '1') {
                one ++;
            }
            else{
                zero ++;
            }
        }

        ll mn = min(one , zero);
        if(mn & 1) {
            cout << "DA" << endl;
        }
        else{
            cout << "NET" << endl;
        }
    }
    return 0;
}

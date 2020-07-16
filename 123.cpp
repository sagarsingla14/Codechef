#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , x;
        cin >> n >> x;
        string str;
        cin >> str;
        ll l = str.length();
        ll one = 0, zero = 0;
        for(ll i = 0 ; i < l ; i++) {
            if(str[i] == '0') {
                zero ++;
            }
            else{
                one ++;
            }
        }
        ll lhs = zero - one;
        cout <<" lhs - > " << lhs;
        if(lhs == 0) {
            cout << -1 << endl;
            continue;
        }
        ll rhs = l * x;
        cout <<" l - > " << l;

        cout <<" rhs - > " << rhs;
        ll val = rhs / lhs;
        cout <<" val - > " << val;
        cout << endl;

        if(val < 0) {
            cout << 0 << endl;
        }
        else{
            ll index = val % l;

            ll count = 0;
            ll z = 0, o = 0;
            for(ll i = 0 ; i < l ; i++) {
                if(str[i] == '0') {
                    z ++;
                }
                else{
                    o ++;
                }

                if(abs(z - o) == 0) {
                    count ++;
                }
                index ++;
                index %= l;
            }
            z = 0, o = 0;
            if(val == 0) {
                cout << count + 1 << endl;
                continue;
            }

            index = (val - 1) % l;

            string s = "";
            for(ll i = index - 1 ; i >= 0 ; i--) {
                s += str[i];
            }
            for(ll i = l - 1 ; i >= index ; i--) {
                s += str[i];
            }
            for(ll i = 0 ; i < l ; i++) {
                if(str[i] == '0') {
                    z ++;
                }
                else{
                    o ++;
                }
                if(abs(z - o) == 0) {
                    count ++;
                }
            }
            cout << count + 1 << endl;
        }

    }
    return 0;
}

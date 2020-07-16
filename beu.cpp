#include <bits/stdc++.h>
#define ll long long 
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
        ll one = 0, ll zero = 0;
        for(ll i = 0 ; i < l ; i++) {
            if(str[i] == '0') {
                zero ++;
            }
            else{
                one ++;
            }
        }
        ll lhs = zero - one;
        ll rhs = l * x;

        ll val = rhs / lhs;
        if(val == 0){
            cout << -1 << endl;
        }
        else{
            if(val < 0) {
                cout << 0 << endl;
            }
            else{
                ll index = val % l;

                ll count = 0;
                ll z = 0, o = 0;
                for(ll i = index ; i < l ; i++) {
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
                z = 0, o = 0;
                index = (val - 1) % l;
                for(ll i = index ; i >= 0 ; i--) {
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
    }
    return 0;
}

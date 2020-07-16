#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll n = str.length();
        ll one = 0 , zero = 0;

        vector <ll> a , b;
        for(ll i = 0 ; i < n ; i++) {
            if(str[i] == '1') {
                one ++;
                a.push_back(i);
            }
            else {
                zero ++;
                b.push_back(i);
            }
        }

        if(one == n || zero == n) {
            cout << 0 << endl;
        }
        else {
            ll doneOne = 0 , doneZero = 0;
            ll ans = 1e10;

            for(ll i = 0 ; i < n ; i++) {
                string s = "";
                for(ll j = 0 ; j < n ; j++) {
                    if(j < i) {
                        s += '1';
                    }
                    else{
                        s += '0';
                    }
                }
                ll cnt = 0;
                for(ll j = 0 ; j < n ; j ++) {
                    if(str[j] != s[j]) {
                        cnt ++;
                    }
                }
                ans = min(ans , cnt);
            }

            for(ll i = 0 ; i < n ; i++) {
                string s = "";
                for(ll j = 0 ; j < n ; j++) {
                    if(j < i) {
                        s += '0';
                    }
                    else{
                        s += '1';
                    }
                }

                ll cnt = 0;
                for(ll j = 0 ; j < n ; j ++) {
                    if(str[j] != s[j]) {
                        cnt ++;
                    }
                }
                ans = min(ans , cnt);
            }

            cout << ans << endl;
        }
    }
    return 0;
}

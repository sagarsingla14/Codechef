#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007


int main() {
    ll t;
    cin >> t;
    ll x = 0;
    while(t--) {
        x ++;
        string str;
        cin >> str;
        ll n = str.length();
        string ans = "";
        ll open = 0;
        for(ll i = 0 ; i < n ; i++) {
            ll digit = str[i] - '0';
            ll diff = digit - open;
            open += diff;
            if(diff >= 0) {
                for(ll j = 0 ; j < diff ; j++) {
                    ans += "(";
                }
                ans += str[i];
            }
            else{
                diff = abs(diff);
                for(ll j = 0 ; j < diff ; j++) {
                    ans += ")";
                }
                ans += str[i];
            }
        }

        if(open) {
            while(open --) {
                ans += ")";
            }
        }

        cout << "Case #" << x << ": " << ans << endl;
    }
    return 0;
}

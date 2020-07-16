#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string str;
        cin >> str;

        ll flag = 0;
        ll fwd = 0 ,  bwd = 0;
        ll l = str.length();
        for(ll i = 1 ; i <= l ; i++) {
            if(str[i-1] == '1') {
                fwd = i;
            }
        }
        ll count = 0;
        for(ll i = l-1 ; i >= 0 ; i--) {
            count ++;
            if(str[i] == '1') {
                bwd = count;
            }
        }
        if(fwd == 0) {
            cout << n << endl;
        }
        else{
            ll mx = max(fwd , bwd);
            cout << 2 * mx << endl;
        }
    }
    return 0;
}

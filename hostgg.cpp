#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {

    ll n , x , y;
    cin >> n >> x >> y;
    string str;
    cin >> str;

    ll one = 0 , zero = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(str[i] == '1') {
            one ++;
        }
        else{
            zero ++;
        }
    }

    if(one == n) {
        cout << 0 << endl;
    }
    else if(zero == n) {
        cout << y << endl;
    }
    else {
        ll i = 0;
        vector <char> v;
        while(i < n) {
            ll j = i;
            v.push_back(str[i]);

            while(j < n && str[j] == str[i]) {
                j ++;
            }
            i = j;
        }

        ll cntA = 0;
        for(ll i = 1 ; i < v.size() ; i++) {
            if(v[i] == '0') {
                cntA ++;
            }
        }

        ll cntB = 0;
        for(ll i = v.size() - 2 ; i >= 0 ; i--) {
            if(v[i] == '0' && v[i + 1] == '1') {
                cntB ++;
            }
        }

        // cout << cntA << " " << cntB << endl
        //
        // for(auto i : v) {
        //     cout << i << " ";
        // }
        // cout << endl;

        // ll valaB = cntA * x + y;
        // if(v[0] == '0') {
        //     cntA ++;
        // }
        // ll valaA = cntA * y;
        //
        // ll valbB = cntB * x + y;
        // if(v[v.size() - 1] == '0') {
        //     cntB ++;
        // }
        // ll valbA = cntB * y;
        //
        // ll ans = 9e18;
        // ans = min(ans , valaA);
        // ans = min(ans , valaB);
        //
        // ans = min(ans , valbA);
        // ans = min(ans , valbB);

        cout << (cntA - 1) * min(x , y) + y << endl;
    }
    return 0;
}

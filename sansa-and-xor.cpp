#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll ans;
ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    if(y & 1) {
        return pw * pw * x;
    }
    else{
        return pw * pw;
    }
}

void calc(ll a , ll b) {
    ll la = log2(a);
    ll lb = log2(b);
    la ++ , lb ++;
    ll ta = a, tb = b;
    string abin = "", bbin = "";
    for(ll i = 0 ; i < la ; i++) {
        ll bit = (a & 1);
        abin += ('0' + bit);
        a >>= 1;
    }
    for(ll i = 0 ; i < lb ; i++) {
        ll bit = (b & 1);
        bbin += ('0' + bit);
        b >>= 1;
    }
    if(la != lb) {
        if(la > lb) {
            while(bbin.length() < la) {
                bbin += '0';
            }
        }
        else{
            while(abin.length() < lb) {
                abin += '0';
            }
        }
    }

    reverse(abin.begin() , abin.end());
    reverse(bbin.begin() , bbin.end());
    ll l = max(la , lb);
    string res = "";

    // cout << abin << endl << bbin << endl;
    ll one = 0;
    ll stop = 0;
    for(ll i = 0 ; i < l ; i++) {
        if(abin[i] != bbin[i]) {
            stop = 1;
            res += '0';
        }
        else if(abin[i] == bbin[i] && !stop) {
            res += abin[i];
        }
        else{
            res += '0';
        }
    }

    // cout << res << endl;

    ans = 0;
    reverse(res.begin() , res.end());
    for(ll i = 0 ; i < l ; i++) {
        if(res[i] == '1') {
            ans += power(2 , i);
        }
    }
    cout << ans << endl;
}

int main() {
    ll t;
    cin >> t;
    cout << (-10 % 3) << endl;

    while(t--) {
        ll a, b;
        cin >> a >> b;
        calc(a , b);
    }
    return 0;
}

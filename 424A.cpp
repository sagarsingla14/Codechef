#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
int main() {
    ll n;
    cin >> n;
    string str;
    cin >> str;
    ll x = 0, xx = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(str[i] == 'x') {
            x++;
        }
        else{
            xx++;
        }
    }

    ll ans = 0;
    if(x > xx) {
        ll i = 0;
        while(x != xx && i <= n - 1) {
            if(str[i] == 'x') {
                str[i] = 'X';
                x --;
                xx ++;
                ans ++;
            }
            i ++;
        }
    }
    else{
        ll i = 0;
        while(x != xx && i <= n - 1) {
            if(str[i] == 'X') {
                str[i] = 'x';
                x ++;
                xx --;
                ans ++;
            }
            i ++;
        }
    }

    cout << ans << endl << str << endl;
    return 0;
}

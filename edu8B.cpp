#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string str;
ll ans = 0;

int main() {
    cin >> str;
    ll n = str.length();
    for(ll i = 0 ; i < n ; i ++) {
        ll num = str[i] - '0';
        if(num % 4 == 0) {
            ans ++;
        }
    }

    for(ll i = 1 ; i < n ; i++) {
        ll num = (str[i - 1] - '0') * 10 + (str[i] - '0');
        if(num % 4 == 0) {
            ans += i;
        }
    }
    cout << ans << endl;

    return 0;
}

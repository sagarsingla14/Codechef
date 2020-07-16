#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
int main() {
    ll n;
    cin >> n;
    string str , s;
    str = "0";
    cin >> s;
    str += s;
    str += "0";
    char c = 'z';
    ll ans = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(str[i] == c) {
            if(str[i - 1] - 1 == str[i] || str[i + 1] - 1 == c) {
                str[i] = "*";
                ans ++;
            }
        }
    }


}

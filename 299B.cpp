#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll ans;
int main() {
    string str;
    cin >> str;
    ll n = str.length();

    ans = (1 << n) - 2;
    reverse(str.begin() , str.end());
    for(ll i = 0 ; i < n ; i++) {
        if(str[i] == '7') {
            ans += (1 << i);
        }
    }
    ans ++;
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n;
    cin >> n;
    string str;
    cin >> str;

    ll ans = 0;
    for(ll i = 0 ; i < n - 2 ; i++) {
        if(str[i] == '0' && str[i + 1] == '1' && str[i + 2] == '0') {
            ans ++;
            str[i + 2] = '1';
        }
    }

    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    string str;
    cin >> str;
    ll m;
    cin >> m;
    while(m--) {
        ll l , r , k;
        cin >> l >> r >> k;
        ll length = abs(l - r) + 1;
        ll shift = k % length;
        vector <char> v;
        for(ll i = l - 1 ; i < r ; i++) {
            v.push_back(str[i]);
        }
        ll j = 0;
        for(ll i = 0 ; i < length ; i++) {
            ll x = (j + shift) % length;
            str[l - 1 + x] = v[j];
            j++;
        }
    }
    cout << str << endl;
    return 0;
}

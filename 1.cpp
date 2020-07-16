#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        ll l = str.length();
        ll ans = 0;
        vector <ll> ind;
        for(ll i = 0 ; i < l - 2 ; i++) {
            if(str[i] == 't') {
                if(str[i + 1] == 'w' && str[i + 2] == 'o') {
                    ans++;
                    str[i + 2] = 'x';
                    ind.push_back(i + 2);
                }
            }
            if(str[i] == 'o') {
                if(str[i + 1] == 'n' && str[i + 2] == 'e') {
                    ans++;
                    str[i] = 'x';
                    ind.push_back(i);
                }
            }
        }
        cout << ans << endl;
        for(ll i = 0; i < ans ; i++) {
            cout << ind[i] << " ";
        }
        cout << endl;
    }
}

#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
using namespace std;
int main() {
    ll n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    ll ab = 0 , ba = 0;
    vector <ll> indexab;
    vector <ll> indexba;
    for(ll i = 0 ; i < n ; i++) {
        if(s[i] == 'a' && t[i] == 'b') {
            ab ++;
            indexab.push_back(i + 1);
        }
        else if(s[i] == 'b' && t[i] == 'a') {
            ba ++;
            indexba.push_back(i + 1);
        }
    }
    if((ab + ba) % 2) {
        cout << -1 << endl;
    }
    else{
        ll ans = 0;
        ans += (ab / 2);
        if(ab % 2) {
            ans ++;
        }
        ans += (ba / 2);
        if(ba % 2) {
            ans ++;
        }
        cout << ans << endl;
        // if(ab > 1) {
            for(ll i = 0 ; i < ab - 1 ; i += 2) {
                // if(i + 1 < ab) {
                    cout << indexab[i] << " " << indexab[i + 1] << endl;
                // }
            }
        // }

        // if(ba > 1) {
            for(ll i = 0 ; i < ba - 1; i += 2) {
                // if(i + 1 < ba) {
                    cout << indexba[i] << " " << indexba[i + 1] << endl;
                // }
            }
        // }

        if(ab % 2 && ba % 2) {
            cout << indexab[ab - 1] << " " << indexab[ab - 1] << endl;
            cout << indexab[ab - 1] << " " << indexba[ba - 1] << endl;
        }


    }
    return 0;
}

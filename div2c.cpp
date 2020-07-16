#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll b[n] = {0};
        ll flag = 0;
        ll one = 0;
        ll freq[2 * n + 1] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> b[i];
            if(b[i] == 2 * n) {
                flag = 1;
            }
            if(b[i] == 1) {
                one = 1;
            }
            freq[b[i]] = 1;
        }
        if(flag || one == 0) {
            cout << -1 << endl;
        }
        else{
            vector <ll> v;
            ll check = 0;
            for(ll i = 0 ; i < n ; i++) {
                check = 0;
                v.push_back(b[i]);
                for(ll j = b[i] ; j <= 2 * n ; j++) {
                    if(freq[j] == 0) {
                        freq[j] = 1;
                        v.push_back(j);
                        check = 1;
                        break;
                    }
                }
                if(check == 0) {
                    break;
                }
            }

            if(check == 0) {
                cout << -1 << endl;
            }
            else{
                for(ll i = 0 ; i < v.size() ; i++) {
                    cout << v[i] << " ";
                }
                cout << endl;
            }

        }
    }
    return 0;
}

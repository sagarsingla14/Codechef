#include <bits/stdc++.h>
using namespace std;
#define base 1000000007
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , s , k;
        cin >> n >> s >> k;
        ll arr[k] = {0};
        map <ll , ll> m;
        for(ll i = 0 ; i < k ; i++) {
            cin >> arr[i];
            m[arr[i]] = 1;
        }

        if(m[s] == 0) {
            cout << 0 << endl;
            // continue;
        }
        else{
            ll ansf = 0, ansb = 0;
            for(ll i = 0 ; i <= 1000 ; i++) {
                if(m[s + i] != 0 && s + i <= n) {
                    ansf ++;
                }
                else{
                    if(s + i > n) {
                        ansf = INT_MAX;
                    }
                    break;
                }
            }
            for(ll i = 0 ; i <= 1000 ; i++) {
                if(m[s - i] != 0) {
                    ansb ++;
                }
                else{
                    if(s - i < 1) {
                        ansb = INT_MAX;
                    }
                    break;
                }
            }
            // cout << ansf << " " << ansb << endl;
            cout << min(ansf, ansb) << endl;
        }
    }
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main () {
    ll t , s;
    cin >> t >> s;
    while(t--) {
        ll n;
        cin >> n;
        ll a[n] , b[n];
        for(ll i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        for(ll i = 0 ; i < n ; i++){
            cin >> b[i];
        }

        sort(a , a + n);
        sort(b , b + n);

        ll flag = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(a[i] >= b[i]) {
                flag = 1;
                break;
            }
        }

        if(flag) {
            cout << "NO" << endl;
        }
        else{
            unordered_map <ll , ll> mp;
            mp[a[0]] = 1;
            for(ll i = 0 ; i < n ; i++) {
                if(mp[a[i]]) {
                    if(b[i] > a[i]) {
                        mp[b[i]] = 1;
                        mp[a[i]] = 1;
                    }
                    else{
                        flag = 1;
                        break;
                    }
                }
                else{
                    flag = 1;
                    break;
                }
            }

            if(flag) {
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}

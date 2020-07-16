#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;
        string arr[n];
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        string ans = arr[0];

        ll found = 0;
        for(ll i = 0 ; i < m ; i ++) {
            char cur = ans[i];
            for(ll j = 0 ; j < 26 ; j ++) {
                ans[i] = 'a' + j;
                ll flag = 1;
                for(ll k = 0 ; k < n ; k ++) {
                    ll cnt = 0;
                    for(ll l = 0 ; l < m ; l ++) {
                        if(arr[k][l] != ans[l]) {
                            cnt ++;
                        }
                    }
                    if(cnt > 1) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    found = 1;
                    break;
                }
            }
            if(found) {
                break;
            }
            ans[i] = cur;
        }

        if(found) {
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}

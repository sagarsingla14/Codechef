#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main () {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m ;
        cin >> n >> m;
        vector <ll> arr[n];
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < m ; j++) {
                ll x;
                cin >> x;
                arr[i].push_back(x);
            }
        }
        ll ans = n * m;
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < m ; j++) {
                ll hl = j - 1;
                ll hr = j + 1;
                ll vu = i - 1;
                ll vd = i + 1;
                ll count = 0;
                while (hl >= 0 && hr <= m - 1 && vu >= 0 && vd <= n - 1) {
                    if(arr[vu][j] == arr[vd][j] && arr[i][hl] == arr[i][hr] )  {
                        vu --;
                        vd ++;
                        hr ++;
                        hl --;
                        count ++;
                    }
                    else{
                        break;
                    }
                }
                ans += count;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

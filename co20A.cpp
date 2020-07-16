#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string a , b;
        cin >> a >> b;
        ll n = a.length();
        ll arr[n + 1] = {0};
        ll ans = n;
        if(a == b) {
            cout << 0 << endl;
        }
        else{
            vector <ll> v;
            ll diff = 0;
            for(ll i = 0 ; i < n ; i++) {
                if(a[i] != b[i]) {
                    diff ++;
                    arr[i] = 1;
                    v.push_back(i + 1);
                }
            }

            for(ll i = 1 ; i < n ; i++) {
                if(arr[i]) {
                   arr[i] += arr[i - 1];
                }
            }
            ll k = 0;
            for(ll i = 0 ; i < n ; i++) {
                if(arr[i + 1] == 0 && arr[i] != 0) {
                    k ++;
                }
            }
            ll sum = 0;
            for(ll i = 0 ; i < n ; i++) {
                if(arr[i + 1] == 0) {
                    sum += arr[i];
                }
            }

            ans = min(ans , sum * k);
            if(k == 1) {
                cout << diff << endl;
                continue;
            }

            ll ss = v.size();
            ll mn = v[0];
            ll mx = v[ss - 1];
            vector <ll> val;

            ll fail = abs(mx - mn) + 1;
            //
            // for(auto i : v) {
            //     cout << i << " ";
            // }
            // cout << endl;

            for(ll i = 0 ; i < ss - 1; i++) {
                ll temp = abs(v[i] - mn + 1) + abs(mx - v[i + 1] + 1);
                temp *= 2;
                val.push_back(temp);
            }


            // for(auto i : val) {
            //     cout << i << " ";
            // }
            // cout << endl;

            for(auto i : val) {
                ans = min(ans , i);
            }

            ans = min(ans , fail);

                cout << ans << endl;
        }

    }
    return 0;
}

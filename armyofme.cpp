#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n , q ;
    cin >> n >> q ;
    ll arr[n + 1] = {0} ;

    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    // vector <ll> dp[n + 1];
    // for(ll i = 0 ; i <= n ; i++) {
    //     for(ll j = 0 ; j <= n ; j++) {
    //         dp[i].push_back(0);
    //     }
    // }
    //
    // for(ll i = 1 ; i <= n ; i++) {
    //     dp[1][i] = 1;
    // }
    //
    // for(ll i = 2 ; i <= n ; i++) {
    //     for(ll j = i ; j <= n ; j++) {
    //         ll flag = 0;
    //         ll x = j - 1;
    //         ll count = 1;
    //         while(count <= (i - 1)) {
    //             if(arr[x] + 1 == arr[j] || arr[x] - 1 == arr[j]) {
    //                 flag = 1;
    //                 break;
    //             }
    //             count ++;
    //             x--;
    //         }
    //         if(flag) {
    //             dp[i][j] = dp[i - 1][j - 1] + 1;
    //         }
    //         else{
    //             dp[i][j] = 1;
    //         }
    //     }
    // }
    //
    // for(ll i = 0 ; i <= n ; i++) {
    //     for(ll j = 0 ; j <= n ; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    ll last = 0 ;
    while(q--) {
        ll x , y;
        cin >> x >> y;
        ll l = ((x + last - 1) % n) + 1;
        ll r = ((y + last - 1) % n) + 1;
        // cout << l << " l r " << endl;
        if(l > r) {
            swap(l , r);
        }
        // cout << l << " <- L  R -> " << r << endl;
        // last = dp[abs(r - l + 1)][r];
        // cout << last << endl;
        ll ans = 1;
        for(ll i = l ; i <= r  ; i++) {
            for(ll j = i ; j <= r ; j++) {
                vector <ll> v;
                for(ll x = i ; x <= j ; x++) {
                    v.push_back(arr[x]);
                }
                sort(v.begin() , v.end());
                ll s = v.size();
                ll flag = 0;
                for(ll x = 0 ; x < s - 1 ; x++) {
                    if(v[x] + 1 != v[x + 1]) {
                        flag = 1;
                    }
                }
                if(!flag) {
                    ans = max(ans , s);
                }
            }
        }
        last = ans;
        cout << last << endl;
    }
    return 0;
}

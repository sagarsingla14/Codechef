#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

ll power(ll x , ll y){
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;

        ll arr[n + 1] = {0};
        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }

        ll c[n + 1][m + 1];
        memset(c , 0 , sizeof(c));

        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= m ; j++) {
                cin >> c[i][j];
            }
        }

        // vector <pair <ll , pair <ll , ll>>> dp[n + 1];
        vector <pair <ll , pair <ll , pair <ll , ll>> > > dp[n + 1];

        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= m ; j++) {
                pair <ll , pair <ll , pair <ll , ll>>> p;

                p.first = c[i][j] + arr[i];
                p.second.first = 0;
                p.second.second.first = j;
                p.second.second.second = i;

                dp[i].push_back(p);

                arr[i] = arr[i] + c[i][j];
            }
        }

        vector <pair <ll , pair <ll , pair <ll , ll>> > > final[m + 1];

        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 0 ; j < m ; j++) {
                final[dp[i][j].second.second.first].push_back(dp[i][j]);
            }
        }

        for(ll i = 1 ; i <= m ; i++) {
            sort(final[i].rbegin() , final[i].rend());
        }

        for(ll i = 1 ; i <= n ; i++) {
            sort(dp[i].rbegin() , dp[i].rend());
        }

        for(ll i = 1 ; i <= m ; i ++) {
            for(ll j = 0 ; j < n ; j++) {
                if(j == 0) {
                    final[i][j].second.first = 1;
                }
                else{
                    if(final[i][j].first == final[i][j - 1].first) {
                        final[i][j].second.first = final[i][j - 1].second.first;
                    }
                    else{
                        final[i][j].second.first = 1 + final[i][j - 1].second.first;
                    }
                }
            }
        }

        vector <pair <ll , pair <ll , ll>>> r[n + 1];

        for(ll i = 1 ; i <= m ; i++) {
            for(ll j = 0 ; j < n ; j++) {
                pair <ll , pair <ll , ll>> p;
                // rnk
                p.first = final[i][j].second.first;
                // r[final[i][j].second.second.second].first = final[i][j].second.first;
                // // month
                p.second.first = final[i][j].second.second.first;
                // .second.first = final[i][j].second.second.first;
                // // player
                p.second.second = final[i][j].second.second.second;
                // r[final[i][j].second.second.second].first.second = final[i][j].second.second.second;
                r[final[i][j].second.second.second].push_back(p);
            }
        }

        for(ll i = 1 ; i <= n ; i++) {
            sort(r[i].begin() , r[i].end());
        }


        map <ll , vector <ll>> rat , rnk;
        for(ll i = 1 ; i <= n ; i++) {
            vector <ll> v;
            ll mx = dp[i][0].first;

            for(ll j = 0 ; j < m ; j++) {
                if(mx == dp[i][j].first) {
                    v.push_back(dp[i][j].second.second.first);
                    // break;
                }
            }
            rat[i] = v;
        }

        for(ll i = 1 ; i <= n ; i++) {
            vector <ll> v;
            ll mx = r[i][0].first;

            for(ll j = 0 ; j < m ; j++) {
                if(mx == r[i][j].first) {
                    v.push_back(r[i][j].second.first);
                    // break;
                }
            }
            rnk[i] = v;
        }

        int ans = 0;

        for(ll i = 1 ; i <= n ; i++) {
            sort(rnk[i].begin() , rnk[i].end());
            sort(rat[i].begin() , rat[i].end());
        }

        for(ll i = 1 ; i <= n ; i++) {
            // ll ok = 0;
            // for(auto it : rnk[i]) {
            //     for(auto it1 : rat[i]) {
            //         if(it != it1) {
            //             ok = 1;
            //             break;
            //         }
            //     }
            //     if(ok) {
            //         break;
            //     }
            // }
            if(rnk[i][0] != rat[i][0]) {
                ans ++;
            }
        }

        //
        // cout << "rnk" << endl;
        // for(ll i = 1 ; i <= n ; i++) {
        //     for(auto j : rnk[i]) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        //
        // cout << endl;
        // cout << "rat" << endl;
        // for(ll i = 1 ; i <= n ; i++) {
        //     for(auto j : rat[i]) {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        cout << ans << endl;

        // for(int i = 1 ; i <= m ; i++) {
        //     for(int j = 0 ; j < n ; j++) {
        //         cout << i << " " << j << endl;
        //         cout << dp[i][j].first << " " << dp[i][j].second.second << endl;
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}

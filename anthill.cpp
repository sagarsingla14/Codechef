#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n , m , a , r ;
    vector <pair <ll , ll> > vec;
    cin >> n >> m >> a >> r ;

    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        vec.push_back(make_pair(u , v));
    }

    ll val1 = m * a;

    // ll total = (n * (n - 1)) / 2;
    // total -= (2 * m) ;
    // val2 += (total * r);
    //
    // if(val1 >= val2) {
    //
    // }
    // else{
        // ll dp[n][n];
        // for(ll i = 0 ; i <  n ; i++) {
        //     for(ll j = 0 ; j < n ; j++) {
        //         if(i != j) {
        //             dp[i][j] = 1;
        //         }
        //         else{
        //             dp[i][j] = 0;
        //         }
        //     }
        // }
        //
        // for(ll i = 0 ; i < m ; i++) {
        //     dp[vec[i].first - 1][vec[i].second - 1] = 0;
        //     dp[vec[i].second - 1][vec[i].first - 1] = 0;
        // }
        // cout << total + n << endl;


        // ll count = 0;
        // for(ll i = 0 ; i <  n ; i++) {
        //     for(ll j = i ; j < n ; j++) {
        //         if(dp[i][j]) {
        //             count++;
        //             // cout << "2 " << i + 1 << " " << j + 1 << endl;
        //         }
        //         // cout << dp[i][j] << " ";
        //     }
        //     // cout << endl;
        // }

        // ll val2 = n * a + r * count;

        // if(val1 >= val2) {
            cout << m << endl;
            for(ll i = 0 ; i < vec.size() ; i++) {
                cout << 1 << " " << 1 << " " << vec[i].first << " " << vec[i].second << endl;
            }
        // }
        // else{
        //     cout << n + count << endl;
        //     for(ll i = 1 ; i < n  ; i++) {
        //         cout << 1 << " " << 1 << " " << i << " " << (i + 1) << endl;
        //     }
        //     cout << 1 << " " << 1 << " " << n << " " << 1 << endl;
        //
        //     for(ll i = 0 ; i < n ; i++) {
        //         for(ll j = i ; j < n ; j++) {
        //             if(dp[i][j]) {
        //                 cout << "2 " << i + 1 << " " << j + 1 << endl;
        //             }
        //         }
        //     }
        // }
    return 0;
}

// 4 5 10 2
// 1 2
// 2 3
// 3 4
// 4 1
// 1 3


// ans1.push_back(m);

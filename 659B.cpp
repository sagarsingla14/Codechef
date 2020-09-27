#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k , l;
        cin >> n >> k >> l;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        ll dp[n + 1][2 * k + 1];
        memset(dp , 0 , sizeof(dp));

        vector <ll> p;
        for(ll i = 0 ; i <= k ; i++) {
            p.push_back(i);
        }

        for(ll i = k - 1 ; i >= 1 ; i--) {
            p.push_back(i);
        }

        ll maxTime = 2 * k;
        if(arr[0] <= l) {
            dp[0][0] = 1;
        }

        for(ll i = 0 ; i < n - 1 ; i++) {
            for(ll j = 0 ; j < maxTime ; j++) {
                if(dp[i][j]) {
                    nt = (t + 1) % maxTime;

                    if(arr[i + 1] + p[nt] <= l) {
                        dp[i + 1][nt] = 1;
                    }
                    if(arr[i] + p[nt] <= l) {
                        dp[i][nt] = 1;
                    }
                 }
            }
        }
        ll flag = 0;
        for(ll i = 0 ; i < maxTime ; i++) {
            if(dp[n][i]) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << "Yes" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

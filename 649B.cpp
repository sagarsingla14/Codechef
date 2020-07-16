#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ;i++) {
            cin >> arr[i];
        }

        ll flag = 0;
        vector <ll> ans;

        ll dp[n - 1] = {0};
        for(ll i = 0 ; i < n - 1 ; i++) {
            dp[i] = arr[i + 1] - arr[i];
        }

        ans.push_back(arr[0]);
        if(dp[0] < 0) {
            flag = 1;
        }

        for(ll i = 1 ; i < n - 1 ; i++) {
            ll curFlag = 0;
            if(dp[i] < 0) {
                curFlag = 1;
            }

            if(curFlag == flag) {
                continue;
            }
            else{
                ans.push_back(arr[i]);
                if(flag) {
                    flag = 0;
                }
                else {
                    flag = 1;
                }
            }
        }

        ans.push_back(arr[n - 1]);

        cout << ans.size() << endl;
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

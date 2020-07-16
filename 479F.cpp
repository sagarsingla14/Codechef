#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    map <ll , ll> dp;
    ll ans = 1;
    ll val = 0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        dp[arr[i]] = max(dp[arr[i] - 1] + 1 , dp[arr[i]]);
        ans = max(ans , dp[arr[i]]);
        if(ans == dp[arr[i]]) {
            val = arr[i];
        }
    }
    vector <ll> out;
    ll cnt = 0;
    for(ll i = n - 1; i >= 0 ; i--) {
        if(arr[i] == val) {
            out.push_back(i + 1);
            cnt ++;
            val --;
        }
        if(cnt == ans) {
            break;
        }
    }
    reverse(out.begin() , out.end());
    cout << ans << endl;
    for(auto i : out) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}

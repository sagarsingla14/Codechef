// 4
// 6 2
// abaaba
// 6 3
// abaaba
// 36 9
// hippopotomonstrosesquippedaliophobia
// 21 7
// wudixiaoxingxingheclp


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        string str;
        cin >> n >> k >> str;
        ll dp[k][26];

        memset(dp , 0 , sizeof(dp));
        for(ll i = 0 ; i < n ; i++) {
            dp[i % k][str[i] - 'a'] ++;
        }

        ll ans = 0;
        ll m = n / k;
        for(ll i = 0 ; i < k / 2 ; i++) {
            ll mn = INT_MAX;
            for(ll j = 0 ; j < 26 ; j++) {
                ll f = m - dp[i][j];
                ll l = m - dp[k - i - 1][j];
                mn = min(mn , f + l);
            }
            ans += mn;
        }

        if(k % 2) {
            ll mn = INT_MAX;
            for(ll i = 0  ; i < 26 ; i++) {
                ll val = m - dp[k / 2][i];
                mn = min(mn , val);
            }
            ans += mn;
        }
        cout << ans << endl;
    }
    return 0;
}

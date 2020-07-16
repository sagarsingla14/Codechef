#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll n , k;
    string str;
    cin >> n >> k >> str;
    ll ans = 0;
    ll freq[26] = {0};

    map <ll , ll> mp;
    for(ll i = 0 ; i < 26 ; i++) {
        ll cnt = 0;
        for(ll j = 0 ; j < n ; j++) {
            if(str[j] == 'a' + i) {
                cnt ++;
            }
            else {
                cnt = 0;
            }

            if(cnt == k) {
                mp[i] ++;
                cnt = 0;
            }
        }
    }

    for(ll i = 0 ; i < 26 ; i++) {
        ans = max(ans , mp[i]);
    }
    cout << ans << endl;
    // cout << str << endl;

    return 0;
}

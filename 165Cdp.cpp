#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll k;
    string str;
    cin >> k >> str;
    ll l = str.length();
    ll sum[l] = {0};
    ll val = 0;
    map <ll , ll> freq;
    ll o = 0;
    for(ll i = 0 ; i < l ; i++) {
        if(str[i] == '1') {
            val ++;
        }
        if(str[i] == '0') {
            o ++;
        }
        sum[i] = val;
        freq[sum[i]] ++;
    }
    if(o == 0) {
        freq[0] = -1;
    }
    ll ans = 0;

    for(ll i = 0 ; i < l ; i++) {
        if(sum[i] >= k) {
            ans += abs(freq[sum[i] - k]);
            if(sum[i] - k == 0 && freq[sum[i] - k] != -1) {
                ans ++;
            }
        }
    }

    if(k == 0) {
        ans = 0;
        ll add = 0;
        for(ll i = 0 ; i < l ; i++) {
            if(str[i] == '1') {
                add = 0;
            }
            else{
                add ++;
                ans += add;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

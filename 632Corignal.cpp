#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll arr[n + 1] = {0};
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }
    ll sum[n + 1] = {0};
    ll ans = (n * (n + 1)) / 2;
    unordered_map <ll , ll> mp;
    mp[0] ++;
    for(ll i = 1 ; i <= n ; i++) {
        sum[i] = sum[i - 1] + arr[i];
        mp[sum[i]] ++;
    }
    ll minus = 0;
    for(auto i : mp) {
        ll val = i.second;
        minus += ((val * (val - 1)) / 2);
    }
    if( ans - 2 *  minus + 1 <= 0) {
        cout << 0 << endl;
        return 0;
    }
    else{
        cout << ans - 2 *  minus + 1 << endl;
    }
    return 0;
}

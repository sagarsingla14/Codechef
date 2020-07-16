#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n , r;
    cin >> n >> r;
    ll arr[n] = {0};
    unordered_map <ll , ll> mp;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        mp[arr[i]] ++;
    }

    ll ans = 0;
    unordered_map <ll , ll> cur;
    for(ll i = 0 ; i < n ; i++) {
        cur[arr[i]] ++;
        if(arr[i] % r == 0 && i != 0 && i != n - 1) {
            ll a , b;
            a = arr[i] / r;
            b = arr[i] * r;
            ll cnta = cur[a];
            // cout << "a b " << a << " " << b << endl;
            ll cntb = mp[b] - cur[b];
            // cout << "ca cb " << cnta << " " << cntb << endl;
            ans += (cnta * cntb);
        }
    }
    if(r == 1) {
        ans = 0;
        for(auto i : mp) {
            if(i.second >= 3) {
                ll one = i.second;
                ll val = (one) * (one - 1) * (one - 2);
                val /= 6;
                ans += val;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

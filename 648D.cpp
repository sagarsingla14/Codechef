#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    map <ll , ll> mp;

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    set <ll> prev , cur;

    for(ll i = 0 ; i < n ; i++) {
        if(i == 0) {
            mp[arr[i]] ++;
        }
        else {
            for(auto itr : mp) {
                ll val = (itr.first | arr[i]);
                cur.insert(val);
            }

            cur.insert(arr[i]);

            for(auto itr : cur) {
                mp[itr] ++;
            }

            cur.clear();
        }
    }

    ll ans = 0;
    for(auto i : mp) {
        ll cnt = 0;
        ll val = i.first;
        while((val & 1ll) == 1) {
            val >>= 1ll;
            cnt ++;
        }
        ans = max(ans , cnt);
    }

    ll res = 1ll << ans;
    res --;
    cout << res << endl;


    return 0;
}

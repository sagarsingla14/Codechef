#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll t;
ll n, k;
ll ans = 0;
unordered_map <ll , ll> mp;

int main() {

    cin >> t;
    ll tc = 0;
    while(t--) {
        tc ++;
        ans = 0;
        cin >> n;
        mp.clear();
        ll arr[n + 1] = {0};

        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }

        unordered_map <ll , ll> cur;
        unordered_map <ll , ll> prev;

        for(ll i = 1 ; i <= n ; i++) {
            if(i == 1) {
                cur[arr[i]] ++;
                for(auto i : cur) {
                    ll sq = sqrt(i.first);
                    if((sq * sq) == i.first) {
                        ans += i.second;
                    }
                }
                prev = cur;
                cur.clear();
            }
            else{
                cur.clear();
                ll val = arr[i];
                ll check = sqrt(val);
                if((check * check) == val) {
                    ans ++;
                }
                for(auto i : prev) {
                    ll num = i.first + val;
                    ll sq = sqrt(num);
                    if((sq * sq) == num) {
                        ans += i.second;
                    }
                    cur[num] = i.second;
                }
                cur[arr[i]] ++;

                prev.clear();
                prev = cur;
            }
        }
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}

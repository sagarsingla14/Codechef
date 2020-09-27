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
        unordered_set <ll> s , ns;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        s.insert(arr[0]);
        unordered_map <ll , ll> mp;
        mp[arr[0]] ++;

        for(ll i = 1 ; i < n ; i++) {
            for(auto itr : s) {
                ns.insert(itr | arr[i]);
            }
            ns.insert(arr[i]);
            s.clear();
            s = ns;
            ns.clear();
            for(auto j : s) {
                mp[j] ++;
            }
        }

        if(mp.size() == (n * (n + 1)) / 2) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

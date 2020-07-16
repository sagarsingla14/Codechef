#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        ll ans = 0;
        set <ll> s;
        unordered_map <ll , ll> mp;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mp[arr[i]] ++;
            s.insert(arr[i]);
        }
        ll d = s.size();
        ll ss = 0;
        for(auto i : mp) {
            ss = max(ss , i.second);
        }

        if(ss == d) {
            cout << ss - 1 << endl;
        }
        else {
            cout << min(ss , d) << endl;
        }
    }
    return 0;
}

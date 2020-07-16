#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        map <ll , ll> mp;
        ll ans = 0;
        ll arr[n] = {0};
        ll flag = 0;
        ll mx = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mp[arr[i]] ++;
            if(mp[arr[i]] > 2) {
                flag = 1;
            }
            mx = max(mx , arr[i]);
        }

        if(flag) {
            cout << 0 << endl;
        }
        else {
            // cout << "mx " << mx << endl;
            for(ll i = 1 ; i <= mx ; i++) {
                if(mp[i] == 0) {
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                cout << 0 << endl;
                continue;
            }
            ll l = -1;
            for(ll i = 1 ; i <= mx ; i++) {
                if(mp[i] == 1) {
                    l = i;
                    break;
                }
            }
            l -= 1;
            if(l == -2) {
                l = n / 2;
            }
            set <ll> s1;
            set <ll> s2;
            for(ll i = 0 ; i < l ; i++) {
                s1.insert(arr[i]);
            }
            for(ll i = l ; i < n ; i++){
                s2.insert(arr[i]);
            }
            ll ans = 0;
            vector <pair <ll , ll> > v;
            if(s1.size() == l && s2.size() == n - l && s1.size() && s2.size()) {
                ans ++;
                v.push_back(make_pair(s1.size() , s2.size()));
            }

            s1.clear();
            s2.clear();
            l = n - l;
            for(ll i = 0 ; i < l ; i++) {
                s1.insert(arr[i]);
            }
            for(ll i = l ; i < n ; i++){
                s2.insert(arr[i]);
            }

            if(s1.size() == l && s2.size() == n - l && s1.size() && s2.size()) {
                ans ++;
                v.push_back(make_pair(s1.size() , s2.size()));
            }
            if(v.size() == 2 && l == (n / 2) && n % 2 == 0) {
                cout << 1 << endl << l << " " << l << endl;
                continue;
            }
            cout << v.size() << endl;

            for(ll i = 0 ; i < v.size() ; i++) {
                cout << v[i].first << " " << v[i].second << endl;
            }
        }
    }
    return 0;
}

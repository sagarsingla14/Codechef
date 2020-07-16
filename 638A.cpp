#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        ll arr[n] = {0};
        ll ok = 1;
        set <ll> s;
        map <ll , ll> mp;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mp[arr[i]] = 1;
            if(arr[i] > k) {
                ok = 0;
            }
            s.insert(arr[i]);
        }

        if(s.size() > k) {
            cout << -1 << endl;
        }
        else{
            vector <ll> ans;
            vector <ll> v;
            for(auto i : s) {
                v.push_back(i);
            }

            ll dist = s.size();
            if(dist < k) {
                ll diff = abs(dist - k);
                for(ll i = 1 ; i <= 200 ; i++) {
                    if(diff > 0 && mp[i] == 0) {
                        v.push_back(i);
                        diff --;
                    }
                    if(diff == 0) {
                        break;
                    }
                }
            }
            dist = v.size();

            ll i = 0 , j = 0;
            while(i < n) {
                j %= dist;
                if(v[j] == arr[i]) {
                    ans.push_back(arr[i]);
                    i ++;
                    j ++;
                    j %= dist;
                }
                else{
                    ans.push_back(v[j]);
                    j ++;
                    j %= dist;
                }
            }
            cout << ans.size() << endl;
            for(auto i : ans) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        ll arr[n] = {0};
        map <ll , ll> mp;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        ll minSum = 1e18;
        for(ll i = 0 ; i < n ; i++) {
            ll val = arr[i] + arr[n - i - 1];
            mp[val] ++;
        }

        vector <pair <ll, ll> > v;
        for(ll i = 0 ; i < n / 2 ; i++) {
            ll mx = max(arr[i] , arr[n - i - 1]);
            ll mn = min(arr[i] , arr[n - i - 1]);
            mx += k;
            mn += 1;
            v.push_back(make_pair(mn , mx));
        }

        sort(v.begin() , v.end());
        // for(auto i : v) {
        //     cout << i.first << " " << i.second << endl;
        // }

        ll l = v[0].first;
        ll r = v[0].second;
        for(auto i : v) {
            l = max(l , i.first);
            r = min(r , i.second);
        }
        // cout << "l r " << l << " " << r << endl;
        ll fixed = l;
        if(l > r) {
            ll sum = 0 , f = 0;
            for(auto i : mp) {
                if(i.second > f) {
                    f = i.second;
                    sum = i.first;
                }
            }
            ll ans = 0;
            for(ll i = 0 ; i < n / 2 ; i++) {
                ll val = arr[i] + arr[n - i - 1];
                if(val != sum) {
                    ll mnn = min(arr[i] , arr[n - i - 1]);
                    ll mxx = max(arr[i] , arr[n - i - 1]);
                    if(mxx + k >= sum) {
                        ans ++;
                    }
                    else{
                        ans += 2;
                    }
                }
            }

            cout << ans << endl;
        }
        else{
            for(ll i = l ; i <= r ; i++) {
                if(mp[i] > mp[fixed]) {
                    fixed = i;
                }
            }
            ll ans = 0;
            // cout <<"fixed " << fixed << endl;
            for(ll i = 0 ; i < n / 2 ; i++) {
                ll val = arr[i] + arr[n - i - 1];
                if(val != fixed) {
                    ans ++;
                }
            }

            cout << ans << endl;
        }
    }
    return 0;
 }

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b) {
    return (a.second > b.second);
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n >> m;
        ll arr[n] = {0};
        unordered_map <ll , ll> mp;
        unordered_set <ll> s;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mp[arr[i]] = 1;
            s.insert(arr[i]);
        }

        if(s.size() == 1) {
            unordered_set <ll> :: iterator itr;
            ll f = 0;
            for(itr = s.begin() ; itr != s.end() ; itr++) {
                if(*itr == 1) {
                    cout << m << endl;
                    f = 1;
                }
            }
            if(f) {
                continue;
            }
        }

        sort(arr , arr + n);
        ll mx = 0;
        vector <pair <ll , ll> > v;
        for(ll i = m ; i >= 1; i --) {
            if(!mp[i]) {
                ll val = 0;
                for(ll j = 0 ; j < n && arr[j] <= i ; j++) {
                    if(i % arr[j]) {
                        val ++;
                    }
                }
                if(val){
                    mx = max(mx , val);
                    v.push_back(make_pair(i , val));
                }
            }
        }
        if(v.size() == 0) {
            cout << 1 << endl;
            continue;
        }
        else{
            vector <ll> ans;
            for(ll i = 0 ; i < v.size() ; i++) {
                if(v[i].second == mx) {
                    ans.push_back(v[i].first);
                }
            }
            sort(ans.begin() , ans.end());

            cout << ans[ans.size() - 1] << endl;
        }
    }
    return 0;
}

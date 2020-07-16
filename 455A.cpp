#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// This whole solution is wrong - Correct Solution in 455ADp.cpp

bool comp(pair <ll , ll> a , pair <ll , ll> b) {
    return a.second < b.second;
}

int main() {
    ll t;
    // cin  >> t;
    t = 1;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i ++) {
            cin >> arr[i];
        }
        map <ll , ll> freq;
        for(ll i = 0 ; i < n ; i++) {
            freq[arr[i]] ++;
        }
        vector <pair <ll , ll> > v;
        for(ll i = 1 ; i <= n ; i++) {
            if(freq[i]) {
                v.push_back(make_pair(i , freq[i] * i));
            }
        }

        sort(v.begin() , v.end() , comp);
        for(ll i = 0 ; i < v.size() ; i ++ ) {
            cout << v[i].first << " " << v[i].second << endl;
        }
        ll visited[n + 1] = {0};
        ll ans = 0;
        for(ll i = v.size() - 1 ; i >= 0 ; i--) {
            ll val = v[i].first;
            if(!visited[val]) {
                ans += v[i].second;
                visited[val] = 1;
                visited[val + 1] = 1;
                visited[val - 1] = 1;
            }
        }
        cout << ans << endl;
    }
}

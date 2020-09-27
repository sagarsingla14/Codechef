#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000


int main() {
    fast_io
    ll n;
    cin >> n;

    ll arr[n] = {0};
    unordered_map <ll , ll> mp;

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        mp[arr[i]] ++;
    }

    vector <ll> v;
    for(auto i : mp) {
        v.push_back(i.first);
    }

    unordered_set <ll> s , prev;
    unordered_map <ll , ll> freq;

    n = v.size();

    for(ll i = 0 ; i < n ; i++) {
        if(i == 0) {
            s.insert(v[i]);
            prev = s;
            s.clear();
            freq[v[i]] ++;
        }
        else{
            s.clear();
            for(auto itr : prev) {
                s.insert(v[i] ^ itr);
            }
            s.insert(v[i]);
            for(auto itr : s) {
                freq[itr] ++;
            }

            prev.clear();
            prev = s;
            s.clear();
        }
    }

    ll ans = 0;
    for(auto i : freq) {
        ans = max(i.first , ans);
    }

    cout << ans << endl;

    return 0;
}

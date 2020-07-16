#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[10];
ll n;
string ans = "";

int main() {
    cin >> n;
    vector <pair <ll , ll> > v;
    unordered_map <ll , ll> mp;
    for(ll i = 1 ; i <= 9 ; i++) {
        ll c;
        cin >> c;
        v.push_back(make_pair(c , i));
        mp[c] = i;
    }
    sort(v.begin() , v.end());

    ll val = v[0].first;
    ll d = v[0].second;

    for(ll i = 0 ; i < 9 ; i++) {
        if(val == v[i].first) {
            if(d <= v[i].second) {
                d = v[i].second;
            }
        }
    }

    if(n < val) {
        cout << -1 << endl;
    }
    else{
        ll times = n / val;
        for(ll i = 0 ; i < times ; i++) {
            ans += '0' + d;
            n -= val;
        }

        ll l = ans.length();
        for(ll i = 0 ; i < l ; i++) {
            n += val;
            ll value = 0;
            ll curdigit = ans[i] - '0';
            for(auto i : mp) {
                if(i.first <= n) {
                    if(i.second >= curdigit) {
                        curdigit = i.second;
                        value = i.first;
                    }
                }
            }
            ans[i] = '0' + curdigit;
            n -= value;
        }
        cout << ans << endl;
    }
    return 0;
}

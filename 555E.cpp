#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll a[200001] , b[200001];
vector <ll> res;
map <ll , ll> mp;
set <ll> s;


int main() {
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    for(ll i = 0 ; i < n ; i++) {
        cin >> b[i];
        s.insert(b[i]);
        mp[b[i]] ++;
    }

    for(ll i = 0 ; i < n ; i++) {
        ll cur = a[i];
        ll reqVal = n - cur;
        auto itr = s.lower_bound(reqVal);

        if(itr != s.end()) {
            ll valUsed = *itr;
            mp[valUsed] --;
            if(mp[valUsed] <= 0) {
                auto pos = s.find(valUsed);
                s.erase(pos);
            }
            res.push_back((cur + valUsed) % n);
        }
        else{
            itr = s.begin();
            ll valUsed = *itr;
            mp[valUsed] --;
            if(mp[valUsed] <= 0) {
                auto pos = s.find(valUsed);
                s.erase(pos);
            }
            res.push_back((cur + valUsed) % n);
        }
    }

    for(auto itr : res) {
        cout << itr  << " ";
    }
    cout << endl;
    return 0;
}

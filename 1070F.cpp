#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector <pair <string , ll> > v;
    ll ans = 0;
    unordered_map <string , ll> mp;
    priority_queue <ll> aa;
    priority_queue <ll> ab;
    priority_queue <ll> ba;
    priority_queue <ll> pq;
    for(ll i = 0 ; i < n ; i++) {
        string s;
        ll val;
        cin >> s >> val;
        if(s == "00") {
            aa.emplace(val);
        }
        if(s == "01") {
            ab.emplace(val);
        }
        if(s == "10") {
            ba.emplace(val);
        }
        if(s == "11") {
            ans += val;
        }
        mp[s] ++;
        v.push_back(make_pair(s , val));
    }
    ll count = min(mp["01"] , mp["10"]);
    for(ll i = 0 ; i < count ; i++) {
        ans += ab.top();
        ans += ba.top();
        ab.pop();
        ba.pop();
    }
    ll left = mp["11"];

    while(!aa.empty()) {
        pq.emplace(aa.top());
        aa.pop();
    }
    while(!ab.empty()) {
        pq.emplace(ab.top());
        ab.pop();
    }
    while(!ba.empty()) {
        pq.emplace(ba.top());
        ba.pop();
    }


    for(ll i = 0 ; i < left ; i++) {
        if(pq.size() == 0) {
            break;
        }
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
    return 0;
}

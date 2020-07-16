#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    map <ll , ll> mp;
    set <ll> s;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        mp[arr[i]] ++;
        s.insert(arr[i]);
    }
    vector <ll> v;
    for(auto i : s) {
        v.push_back(i);
    }

    if(v.size() == 1) {
        if(mp[v[0]] > 1) {
            cout << v[0] << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    ll lcm = 0;
    ll sze = v.size();
    ll k = 0;
    for(ll j = sze - 1 ; j >= 1 ; j --) {
        for(ll i = j - 1; i >= 0 ; i--) {
            ll p = v[j] * v[i];
            ll gcd = __gcd(v[j] , v[i]);
            lcm = max(lcm , (p / gcd));
        }
        k ++;
        if(k == 2) {
            break;
        }
    }
    cout << lcm << endl;
}

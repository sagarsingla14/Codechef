#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 998244353
int main() {
    ll n , k;
    cin >> n >> k;
    ll arr[n] = {0};
    vector <ll> v;
    map <ll , ll> index;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        index[arr[i]] = i;
        v.push_back(arr[i]);
    }
    sort(v.begin() , v.end());
    vector <ll> vals;
    ll pval = 0;
    for(ll i = 0 ; i < k ; i++) {
        vals.push_back(v[n - i - 1]);
        pval += v[n - i - 1];
    }
    vector <pair <ll ,ll> > pos;
    for(ll i = 0 ; i < k ; i++) {
        pos.push_back(make_pair(index[vals[i]] , vals[i]));
    }
    sort(pos.begin() , pos.end());
    if(k == 1) {
        cout << pval << " " << 1 << endl;
    }
    else{
        ll part = 1;
        for(ll i = 0 ; i < k - 1 ; i ++) {
            // cout << pos[i].first << " " << pos[i].second << endl;
            part *= abs(pos[i].first - pos[i + 1].first);
            part %= mod;
        }
        cout << pval << " " << part << endl;
    }
    return 0;

}

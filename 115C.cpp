#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 998244353

bool sortBySec(pair <ll , ll> p1 , pair <ll , ll> p2) {
    return (p1.second < p2.second);
}

int main() {
    ll n;
    cin >> n;
    vector <pair <ll , ll> > v;
    for(ll i = 0 ; i < n ; i++) {
        ll x, y;
        cin >> x >> y;
        v.push_back(make_pair(x , y));
    }
    ll t;
    cin >> t;
    ll arr[t + 1] = {0};
    for(ll i = 1 ; i <= t ; i++) {
        cin >> arr[i];
    }
    sort(v.begin() , v.end() , sortBySec);

    // for(auto i : v) {
    //     cout << i.first << " " << i.second << endl;
    // }

    ll ans = 0;
    ll index = 1;
    ll pointer = 1;
    ll i = 0;
    while(i < n) {
        ll val1 = v[i].first;
        if(val1 == 0) {
            i ++;
            continue;
        }
        ll val2 = arr[index] - arr[index - 1];
        if(val2 == 0) {
            index ++;
            continue;
        }
        // cout << val1 << " " << val2 << " " << i << "  " << index << endl;
        if(val1 >= val2) {
            ll diff = min(val1 , val2);
            ans += (diff * v[i].second * pointer);
            v[i].first -= diff;
            arr[index] -= diff;
            pointer ++;
            index ++;
            i --;
            // cout << "diff1 -> " << diff << endl;
        }
        else{
            ll diff = min(val1 , val2);
            ans += (diff * v[i].second * pointer);
            arr[index] -= diff;
            v[i].first -= diff;
            // cout << "diff2 -> " << diff << endl;
        }
        i ++;
    }

    // cout << "Index -> " << index << endl;

    cout << ans << endl;
    return 0;
}

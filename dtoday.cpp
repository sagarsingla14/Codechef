#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    ll a[n] , b[n];
    vector <ll> ps;
    vector <ll> ng;
    for(ll i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(ll i = 0; i <  n ; i++) {
        cin>>b[i];
    }
    for(ll i = 0 ; i < n ; i++) {
        ll x = a[i] - b[i];
        if(x <= 0) {
            ng.push_back(abs(x));
        }
        else {
            ps.push_back(x);
        }
    }
    ll ans = 0;
    ll p = ps.size();
    ans = (p*(p - 1)) / 2;
    sort(ng.begin(), ng.end());
    sort(ps.begin(), ps.end());

    if(ps.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    for(ll i = 0; i < ng.size() ;  i++) {
        auto it = upper_bound(ps.begin(),ps.end(),ng[i]);
        ll val = it - ps.begin();
        ans += (ps.size() - val);
    }
    ll temp = ps.size();
    cout << ans << endl;
    return 0;
}

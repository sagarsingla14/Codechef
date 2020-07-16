#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll n , d;
    cin >> n >> d;
    ll bit = log2(n);
    vector <ll> ans;
    ll cnt = 0;

    ll val = 0;
    for(ll i = 0 ; i <= bit ; i++) {
        if((n & (1ll << i)) != 0) {
            val += d;
            for(ll j = 0 ; j < i ; j++) {
                ans.push_back(val);
            }
            cnt ++;
        }
    }

    for(ll i = 0 ; i < cnt ; i++) {
        val += d;
        ans.push_back(val);
    }

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int


ll taskOfPairing(vector<ll> arr) {
    ll n = arr.size();
    vector <ll> v;
    ll ans = 0;

    for(ll i = 0 ; i < n ; i++) {
        ans += (arr[i] / 2);
        if(arr[i] % 2) {
            v.push_back(i + 1);
        }
    }

    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    if(v.size() >= 2) {
        for(ll i = 1 ; i < v.size() ; i++) {
            if(v[i] == (v[i - 1] + 1)) {
                ans ++;
                v[i] = 10000000000000;
            }
        }
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    vector <ll> v;
    for(ll i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }

    cout << taskOfPairing(v) << endl;
    return 0;
}

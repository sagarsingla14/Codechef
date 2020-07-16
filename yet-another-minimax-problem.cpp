#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> callMask(ll n) {
    ll i = 0;
    vector <ll> v(32);
    while(n) {
        if((n & 1)) {
            v[31 - i] = 1;
        }
        else{
            v[31 - i] = 0;
        }
        n >>= 1;
        i ++;
    }
    return v;
}

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    set <ll> s;
    vector <vector <ll> > v(n);
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        vector <ll> p = callMask(arr[i]);
        v[i] = p;
        s.emplace(arr[i]);
    }

    if(s.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll sum[32] = {0};
    for(ll i = 0 ; i < 32 ; i++) {
        ll s = 0;
        for(ll j = 0 ; j < n ; j++) {
            if(v[j][i]) {
                s ++;
            }
        }
        sum[i] = s;
    }
    ll direct = 0;
    for(ll i = 0 ; i < 32 ; i++) {
        if(sum[i]) {
            if(sum[i] == n) {
                sum[i] = 0;
            }
            else {
                break;
            }
        }
    }

    ll msb = -1;
    for(ll i = 0 ; i < 32 ; i++) {
        if(sum[i]) {
            msb = i;
            break;
        }
    }

    // cout << msb << endl;
    vector <ll> large , small;
    for(ll i = 0 ; i < n ; i++) {
        if(v[i][msb]) {
            large.push_back(arr[i]);
        }
        else{
            small.push_back(arr[i]);
        }
    }

    if(small.size() == 0 || large.size() == 0) {
        cout << 0 << endl;
    }
    else {
        ll ans = 1e18;
        for(ll i = 0 ; i < small.size() ; i++) {
            for(ll j = 0 ; j < large.size() ; j++) {
                if(ans >= abs(large[j] ^ small[i])) {
                    ans = abs(large[j] ^ small[i]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    ll brr[n] = {0};
    map <ll , ll> a , b;

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        a[arr[i]] = i + 1;
    }
    for(ll i = 0 ; i < n ; i++) {
        cin >> brr[i];
        b[brr[i]] = i + 1;
    }
    
    map <ll , ll> left , right;
    for(auto i : a) {
        ll cur = i.first;
        ll s = a[cur];
        ll e = b[cur];

        if(e >= s) {
            right[e - s] ++;
        }
        else {
            ll add = (n - s) + (e);
            right[add] ++;
        }
    }

    ll ans = 0;
    for(auto i : right) {
        ans = max(ans , i.second);
    }

    cout << ans << endl;
    return 0;
}

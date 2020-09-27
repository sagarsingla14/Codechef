#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    ll mx = 0, e = 0;
    map <ll , ll> mp;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        mp[arr[i]] ++;

        if(mp[arr[i]] > mx) {
            mx = mp[arr[i]];
            e = arr[i];
        }
        else if(mp[arr[i]] == mx) {
            e = max(e , arr[i]);
        }

        cout << e << endl;
    }
    return 0;
}

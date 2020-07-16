#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    ll n , k;
    cin >> n >> k;

    vector <ll> v;
    ll arr[n] = {0};
    ll mx = -1e10 , mn = 1e10;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        v.push_back(arr[i]);
        mx = max(mx , arr[i]);
        mn = min(mn , arr[i]);
    }

    if(k >= 3) {
        cout << mx << endl;
    }
    else if(k == 1){
        cout << mn << endl;
    }
    else {
        sort(arr , arr + n);
        ll val = arr[1];
        if(v[0] > val) {
            val = v[0];
        }
        if(v[n - 1] > val) {
            val = v[n - 1];
        }

        cout << val << endl;
    }
    return 0;
}

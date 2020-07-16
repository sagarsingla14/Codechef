#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll n;
    cin >> n;
    ll arr[n] = {0};

    map <ll , ll> mp;
    for(ll i = 0 ; i < n ;i++) {
        cin >> arr[i];
        mp[arr[i]] ++;
    }

    ll ans[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        ans[i] = -1;
    }

    for(ll i = 1 ; i <= n ; i++) {
        if(arr[i] != arr[i - 1]) {
            ans[i] = arr[i - 1];
        }
    }

    ll need = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(ans[i] == -1) {
            need ++;
        }
    }

    set <ll> s;
    for(ll i = 0 ; i <= 2 * n; i ++) {
        if(!mp[i]) {
            s.insert(i);
        }
        if(s.size() == need) {
            break;
        }
    }

    for(ll i = 0 ; i < n ; i++) {
        if(ans[i] == -1) {
            auto it = s.begin();
            ans[i] = *it;
            s.erase(*it);
        }
    }

    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

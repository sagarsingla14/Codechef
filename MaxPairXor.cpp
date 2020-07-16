#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100001] = {0};
ll n;

void solve() {
    ll ans = 0;
    ll mask = 0;
    for(ll i = 31 ; i >= 0 ; i--) {
        set <ll> s;
        mask += (1ll << i);
        for(ll j = 0 ; j < n ; j++) {
            s.insert(mask & arr[j]);
        }

        for(auto itr : s) {
            if(s.find((ans + (1 << i)) ^  itr) != s.end()) {
                ans += (1 << i);
                break;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    solve();
}

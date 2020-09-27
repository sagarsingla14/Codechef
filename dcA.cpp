#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if (y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

int main() {
    ll ans = 1;
    ll n;
    cin >> n;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    sort(arr , arr + n);

    deque <ll> q;
    q.push_back(arr[0]);
    for(ll i = 1 ; i < n ; i++) {
        while(!q.empty() && arr[i] - q.front() > 5) {
            ll s = q.size();
            ans = max(ans , s);
            q.pop_front();
        }
        q.push_back(arr[i]);
        ll s = q.size();
        ans = max(ans , s);
    }
    ll s = q.size();
    ans = max(ans , s);

    cout << ans << endl;
    return 0;
}

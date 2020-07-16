#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , k , x , ans = 0;
ll arr[100001] = {0};
ll index = 0;

ll cnt(ll mid) {
    ll f = (arr[index] - 1) / x;
    ll e = (arr[mid]) / x;
    return abs(f - e);
}

void solve() {
    ll f = index , l = n;
    ll mx = -1;
    while(f <= l) {
        ll mid = (f + l) / 2;
        if(arr[mid] >= arr[index]) {
            if(cnt(mid) == k) {
                f = mid + 1;
                mx = mid;
            }
            else if(cnt(mid) > k) {
                l = mid - 1;
            }
            else {
                f = mid + 1;
            }
        }
        else{
            f = mid + 1;
        }
    }

    ll mn = -1;
    f = 1 , l = n;
    while(f <= l) {
        ll mid = (f + l) / 2;
        if(arr[mid] >= arr[index]) {
            if(cnt(mid) == k) {
                l = mid - 1;
                mn = mid;
            }
            else if(cnt(mid) > k) {
                l = mid - 1;
            }
            else {
                f = mid + 1;
            }
        }
        else{
            f = mid + 1;
        }
    }

    if(mn != -1 && mx != -1) {
        ans += abs(mx - mn) + 1;
    }
}

int main() {
    cin >> n >> x >> k;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    sort(arr , arr + n + 1);

    for(index = 1 ; index <= n ; index ++) {
        solve();
    }

    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 1000000000000000000

ll n , m , k;
bool solve(ll mid) {
    ll cnt = 0;
    for(ll i = 1 ; i <= n ; i++) {
        cnt += min(m , (mid - 1) / i);
    }
    if(cnt >= k) {
        return false;
    }
    return true;
}

int main() {
    cin >> n >> m >> k;
    ll f = 1 , l = n * m , ans = 0;
    while(f <= l) {
        ll mid = (f + l) >> 1;
        if(solve(mid)) {
            ans = mid;
            f = mid + 1;
        }
        else {
            l = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}

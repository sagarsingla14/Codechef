#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , k;

ll calc(ll x) {
    ll sum = (k * (k + 1)) / 2 - 1;
    ll subSum = ((k - x) * (k - x + 1)) / 2 - 1;

    ll curSum = sum - subSum;
    curSum -= (x - 1);

    return curSum;
}

int main() {
    cin >> n >> k;

    ll sum = (k * (k + 1)) / 2 - 1;
    sum -= (k - 2);

    if(n == 1) {
        cout << 0 << endl;
    }
    else if(sum < n) {
        cout << -1 << endl;
    }
    else {
        ll ans = 0;
        ll f = 1 , l = k - 1;
        while(f <= l) {
            ll mid = (f + l) / 2;
            if(calc(mid) == n) {
                ans = mid;
                break;
            }
            else if(calc(mid) > n) {
                l = mid - 1;
                ans = mid;
            }
            else {
                f = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

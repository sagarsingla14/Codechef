#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll solve(ll d , ll pos , ll n) {

    ll l = 1 , r = pos;
    ll left = -1 , right = -1;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid + d > pos) {
            left = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    l = 1 , r = pos;
    while(l <= r) {
        ll mid = (l + r) / 2;
        if(mid + d <= n) {
            right = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    return abs(left - right) + 1;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll sum = (n * (n + 1)) / 2;

        if(sum % 2) {
            cout << "Ans: " << 0 << endl;
            continue;
        }

        sum /= 2;

        ll ans = 0;
        ll l = 1 , r = n , term = 0;
        ll diff = abs(1 - n);

        while(l <= r) {
            ll mid = (l + r) / 2;
            ll curSum = (mid * (mid + 1)) / 2;
            if(curSum > sum) {
                r = mid - 1;
            }
            else if(sum - curSum <= diff) {
                l = mid + 1;
                term = mid;
            }
            else {
                l = mid + 1;
            }
        }

        l = 1 , r = n;
        ll term1 = 0;
        while(l <= r) {
            ll mid = (l + r) / 2;
            ll curSum = (mid * (mid + 1)) / 2;

            if(curSum > sum) {
                r = mid - 1;
            }
            else if(sum - curSum <= diff) {
                r = mid - 1;
                term1 = mid;
            }
            else {
                l = mid + 1;
            }
        }

        ll left = term1 , right = term;
        for(ll i = left ; i <= right ; i++) {
            ll d = sum - (i * (i + 1)) / 2;
            if(d) {
                ans += solve(d , i , n);
            }
            else{
                ans += (i * (i - 1)) / 2;
                ll rem = n - i;
                ans += (rem * (rem - 1) / 2);
            }
        }

        cout << "Ans: " << ans << endl;
    }
    return 0;
}

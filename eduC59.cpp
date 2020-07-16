#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >>t;
    while(t--) {
        ll a , b , q;
        cin >> a >> b >> q;
        ll gcd = __gcd(a , b);
        ll lcm = (a * b) / gcd;
        ll mx = max(a , b);
        vector <ll> res;
        while(q--) {

            ll l , r;
            cin >> l >> r;
            if(a == b || a % b == 0 || b % a == 0) {
                // cout << 0 << endl;
                res.push_back(0ll);

                continue;
            }
            ll left = l / lcm;
            if(l % lcm) {
                left ++;
            }
            ll right = r / lcm;

            // cout << left << " " << right << endl;
            ll sub = mx - 1;
            // cout << "Sub " << sub << endl;

            ll ans = 0;
            if(right >= left) {
                ans = lcm * abs(right - left);
                // cout << "ans b " << ans << endl;
                ll diff = abs(right - left) * sub;
                ans -= (diff);
                // cout << "ans a " << ans << endl;
                // cout << diff << endl;
            }


            ll leftDiff = abs(l - (left * lcm));

            if(left > right) {
                ans += min(0ll , lcm - sub);
            }
            else{
                ans += min(leftDiff , lcm - sub);
            }
            ll rightDiff = abs(r - (right * lcm));
            if(left > right) {
                ans += max(0ll , rightDiff - sub);
            }
            else{
                ans += min(rightDiff , lcm - sub);
            }

            res.push_back(ans);
        }
        for(auto i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;

    vector <ld> v;

    ll p = 0 , q = 0;
    ld sum = 0;
    while(n --) {
        ll t;
        cin >> t;
        if(t == 1) {
            ll x;
            cin >> x;
            v.push_back(x);
            q ++;

            while(p < q) {
                if(v[p] * (p + 1) < sum + v[q - 1]) {
                    sum += v[p];
                    p ++;
                }
                else {
                    break;
                }
            }
        }
        else {
            ld ans = v[q - 1];
            ans -= (v[q - 1] + sum) / (1.0 * (p + 1));
            cout  << fixed << setprecision(10) << ans << endl;
        }
    }

    return 0;
}

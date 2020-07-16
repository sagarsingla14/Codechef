#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pi 3.14159265

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t --) {
        ld n;
        cin >> n;
        n *= 2.0;
        ld theta = pi / n;

        ld deno = sin(theta);
        ld num = cos(theta / 2.0);

        ld ans = 1.0 / (deno);
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}

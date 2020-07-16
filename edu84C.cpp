#include<bits/stdc++.h>
using namespace std;
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define ld long double
#define ll long long int
ll t;
ld n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        n *= 2.0;

        ld radius = 0.0;
        ld s = 1.0;
        ld deg = 180.0 / n;
        ld rad = (deg * pi) / 180.0;
        ld sn = cos(rad);
        radius = s / double(2.0 * sn);
        ld ans = 1.95 * radius;
        cout << fixed << setprecision(10) << ans << endl;
    }
    return 0;
}

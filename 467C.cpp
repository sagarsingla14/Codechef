#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll k , d;
    ld t;
    cin >> k >> d >> t;

    ld ans = 0;
    ld div = k / d;
    if(k % d) {
        div ++;
    }

    ld totalTime = d * div;
    ld offTime = abs(totalTime - k);
    ld onTime = abs(totalTime - offTime);

    ld avg = (offTime / 2.0 + (1.0 * onTime));
    ll x = t / avg;
    ans = (1.0 * x * totalTime);

    ld rem = t - (avg * x);
    if(rem < onTime) {
        ans += rem;
    }
    else {
        ans += onTime;
        rem = rem - onTime;
        rem *= 2.0;
        ans += rem;
    }

    cout << fixed << setprecision(11) << ans << endl;
    // cout << onTime << " "  << offTime << " " << totalTime << " " << avg << " " << x << " " << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {

        ld h , c , temp;
        cin >> h >> c >> temp;

        if(h == temp) {
            cout << 1 << endl;
        }
        else if(h + c == (2.0 * temp)) {
            cout << 2 << endl;
        }
        else if(temp <= (h + c) / 2) {
            cout << 2 << endl;
        }
        else {
            ld num = abs(temp - h);
            ld deno = abs(c + h - (2.0 * temp));
            ll ans = num / deno;

            ld diffa = (ans * c + (ans + 1) * h) / (1.0 * (2.0 * ans + 1));
            ld diffb = ((ans + 1) * c + (ans + 2) * h) / (1.0 * (2.0 * ans + 3));

            diffa = abs(temp - diffa);
            diffb = abs(temp - diffb);


            if(diffb < diffa) {
                ans ++;
            }

            cout << 2 * ans + 1 << endl;
        }
    }
    return 0;
}

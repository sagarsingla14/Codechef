#include <bits/stdc++.h>
using namespace std;
#define ll int

// HADDD HAIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n , k;
    cin >> n >> k;
    if (n < 2 * k + 1) {
        cout << -1 << endl;
        continue;
    }
    else{
        cout << n * k << endl;
        for(ll i = 0; i < n; i++) {
            for (ll j = 0; j < k; j++) {
                ll next = (i + j + 1) % n;
                cout << i + 1 << " " << next + 1 << endl;
            }
        }
    }
    return 0;
}

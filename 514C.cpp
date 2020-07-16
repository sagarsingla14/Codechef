#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n;
    cin >> n;

    for(ll i = 1 ; i <= n ; i *= 2) {
        if(n / i == 3) {
            cout << i << " " << i << " " << i * 3 << endl;
            break;
        }

        for(ll j = i ; j <= n ; j += (i * 2)) {
            cout << i << " ";
        }
    }
    return 0;
}

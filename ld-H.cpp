#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    ll x;
    cin >> x;

    ll ans = 0;
    while(x) {
        if((x & 1)) {
            ans ++;
        }
        x >>= 1ll;
    }
    cout << ans << endl;
    
    return 0;
}

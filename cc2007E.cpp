#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    ll ans = 1;
    for(ll i = 2 ; i <= 100 ; i++) {
        ans = ans * i / __gcd(ans , i);
        cout << i << " " << ans << endl;
    }
    cout << ans << endl;

    for(ll i = 1 ; i <= 100 ; i++) {
        cout << ans % i << " ";
    }
    cout << endl;
}

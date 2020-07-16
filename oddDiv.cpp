#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m;
ll sq(ll x){
    x %= m;
    return (x * x) % m;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        ll ans = 0;
        while(n) {
            ans += sq(n / 2 + n % 2) % m;
            ans %= m;
            n /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}

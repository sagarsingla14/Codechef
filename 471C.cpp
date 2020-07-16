#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


ll calc(ll x) {
    return (3 * (x * (x + 1)) / 2) - x;
}

int main() {
    ll n;
    cin >> n;
    ll sq = sqrtl(1 + 24 * n);
    ll h = (-1 + (sq)) / 6;

    ll ans = 0;

    for(ll i = 1 ; i <= h ; i++) {
        ll cards = calc(i);
        ll rem = n - cards;
        if(rem % 3 == 0) {
            ans ++;
        }
    }

    cout << ans << endl;

    return 0;
}

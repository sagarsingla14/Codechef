#include <bits/stdc++.h>
using namespace std;
#define base 1000000007
#define ll long long int
int main() {
    ll n;
    cin >> n;
    ll a[n] = {0};
    ll b[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> a[i];
    }

    for(ll i = 0 ; i < n ; i++) {
        cin >> b[i];
    }

    ll ans = 0;
    ll mid = n / 2;
    ll count = mid;
    for(ll i = mid ; i >= 0 ; i--) {
        ans += abs(count - a[i]);
        count ++;
    }
    return 0;

}

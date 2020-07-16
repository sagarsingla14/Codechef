#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

int main() {
    ll t;
    cin >>t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        ll sum = 0;
        for(ll i = 0 ; i < n ; i++) {
            ll x;
            cin >> x;
            sum += x;
        }
        cout << min(sum , k) << endl;
    }
    return 0;
}

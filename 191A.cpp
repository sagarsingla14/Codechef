#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
ll n , ans = 0 , one = 0, zero = 0;

int main() {
    cin >> n;

    for(ll i = 0 ; i < n ; i++) {
        ll x;
        cin >> x;
        if(x) {
            one ++;
        }
        if(!x) {
            zero ++;
            ans = max(ans , zero);
        }
        else if(zero) {
            zero --;
        }
    }

    if(one == n) {
        cout << n - 1 << endl;
    }
    else{
        ans += one;
        cout << ans << endl;
    }

    return 0;
}

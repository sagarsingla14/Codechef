#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;

    while(t--) {
        ll n;
        cin >> n;
        ll sum = 0 , ans = 0;

        cout << 1 << " " << (1 << 20) << endl;
        cin >> sum;

        if(!sum) {
            return 0;
        }

        sum -= (n * (1 << 20));
        if(sum % 2) {
            ans ++;
        }

        for(ll i = 1 ; i <= 19 ; i++) {
            ll curSum;
            cout << 1 << " " << (1 << i) << endl;
            cin >> curSum;
            if(curSum == -1) {
                return 0;
            }

            ll val = (sum - curSum + (n * (1 << i))) / 2;
            val /= (1 << i);

            if(val % 2) {
                ans += (1 << i);
            }
        }

        cout << 2 << " " << ans << endl;

        ll x;
        cin >> x;

        if(x == -1) {
            return 0;
        }
    }
    return 0;
}

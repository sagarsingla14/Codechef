#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n , x;
        cin >> n >> x;
        ll arr[n] = {0};

        ll sum = 0;
        for(ll i = 0 ; i < n ;i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        if(sum % x != 0) {
            cout << n << endl;
        }
        else {
            ll i = 0 , j = n - 1;
            while((arr[i] % x == 0 && arr[j] % x == 0 && i <= j)) {
                i ++;
                j --;
            }

            if(i > j) {
                cout << -1 << endl;
            }
            else {
                sum = 0;
                for(ll k = i ; k <= j ; k ++) {
                    sum += arr[k];
                }

                ll l = (j - i + 1);
                if(sum % x == 0) {
                    l --;
                }

                if(l == 0) {
                    cout << -1 << endl;
                }
                else {
                    cout << l << endl;
                }
            }
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll t , n , x;

int main() {
    fast_io
    cin >> t;
    while(t--) {
        cin >> n >> x;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);
        ll j = n - 1;
        ll cnt = 0 , ans = 0;
        while(j >= 0) {
            cnt ++;
            if(cnt * arr[j] >= x) {
                ans ++;
                cnt = 0;
            }
            j --;
        }
        cout << ans << endl;
    }
    return 0;
}

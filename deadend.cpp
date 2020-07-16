#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        sort(arr , arr + n);
        ll ans = 0;
        ll visited[n] = {0};

        if(n > 1) {
            ll j = 1;
            for(ll i = 0 ; i < n ; i++) {
                ll diff = abs(arr[j] - arr[j - 1]);
                diff --;
                if(diff > 1) {
                    ans ++;
                    visited[j - 1] = 1;
                    j++;
                    // i = j - 2;
                }
                if(diff == 1) {
                    ans++;
                    visited[j - 1] = 1;
                    visited[j] = 1;
                    j += 2;
                    // i ++;
                }
                if(diff == 0) {
                    visited[j - 1] = 1;
                    visited[j] = 1;
                    j += 2;
                }
                if(diff == -1){
                    visited[j] = 1;
                    visited[j - 1] = 1;
                    j++;
                }
                // cout << i << " " << j << " " << ans << endl;
                if(j >= n) {
                    break;
                }

            }

            if(visited[n - 1] == 0) {
                ll diff = abs(arr[n - 1] - arr[n - 2]) - 1;
                if(diff >= 1) {
                    ans ++;
                }
            }
            cout << ans << endl;
        }
        else{
            cout << 1 << endl;
        }

    }
    return 0;
}

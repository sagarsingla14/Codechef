#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        ll arr[n + 1] = {0};
        ll sum[n + 1] = {0};
        ll peak[n + 1] = {0};

        for(ll i = 1 ; i <= n ; i++) {
            cin >> arr[i];
        }

        for(ll i = 2 ; i < n ; i++) {
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                sum[i] = 1;
                peak[i] = 1;
            }
        }

        for(ll i = 2 ; i <= n ; i++) {
            sum[i] += sum[i - 1];
        }

        ll ans = 0;
        ll index = 0;

        for(ll i = 1 ; i <= n - k + 1 ; i++) {
            ll val = abs(sum[i + k - 1] - sum[i - 1]);
            if(peak[i]) {
                val --;
            }
            if(peak[i + k - 1]) {
                val --;
            }
            if(ans < val) {
                ans = val;
            }
        }

        for(ll i = 1 ; i <= n - k + 1 ; i++) {
            ll val = abs(sum[i + k - 1] - sum[i - 1]);
            if(peak[i]) {
                val --;
            }
            if(peak[i + k - 1]) {
                val --;
            }
            if(ans == val) {
                index = i;
                break;
            }
        }

        cout << ans + 1 << " " << index << endl;
    }
    return 0;
}

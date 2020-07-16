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

        if(n == 1) {
            cout << 1 << endl;
            continue;
        }

        sort(arr , arr + n);
        ll ans = 0;
        ll visited[n] = {0};

        if(n == 2) {
            ll diff = arr[1] - arr[0] - 1;
            if(diff > 1) {
                cout << 2 << endl;
            }
            else if(diff == 1){
                cout << 1 << endl;
            }
            else{
                cout << 0 << endl;
            }
            continue;
        }

        for(ll i = 0 ; i < n - 1 ; i++) {
            if(!visited[i]) {
                // if(!visited[i - 1]) {
                //     ll diff = arr[i] - arr[i - 1] - 1;
                //     if(diff > 1) {
                //         ans += 1;
                //         visited[i - 1] = 1;
                //         i--;
                //     }
                //     else if(diff == 1){
                //         ans += 1;
                //         visited[i - 1] = 1;
                //         visited[i] = 1;
                //     }
                //     else{
                //         visited[i - 1] = 1;
                //         visited[i] = 1;
                //     }
                //     continue;
                // }
                if(!visited[i + 1]){
                    ll diff = arr[i + 1] - arr[i] - 1;
                    if(diff > 1) {
                        ans += 1;
                        visited[i] = 1;
                    }
                    else if(diff == 1){
                        ans += 1;
                        visited[i + 1] = 1;
                        visited[i] = 1;
                    }
                    else{
                        visited[i + 1] = 1;
                        visited[i] = 1;
                    }
                    continue;
                }
            }
        }

        if(!visited[n - 1]) {
            ll diff = arr[n - 1] - arr[n - 2] - 1;
            if(diff >= 1) {
                ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

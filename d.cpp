#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll arr[3] = {0};
        for(ll i = 0; i < 3 ; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + 3);
        ll flag = 0;
        if(arr[0] == arr[1] && arr[1] != arr[2]) {
            flag = 1;
        }
        if(arr[0] != arr[1] && arr[1] == arr[2]) {
            flag = 1;
        }
        if(arr[1] != arr[0]) {
            arr[0]++;
        }
        if(arr[2] != arr[1]) {
            arr[2]--;
        }

        ll ans = 0;
        ans = abs(arr[0] - arr[1]);
        ans += abs(arr[1] - arr[2]);
        ans += abs(arr[0] - arr[2]);
        if(flag) {
            ans -= 2;
        }
        cout << ans << endl;
    }
    return 0;
}

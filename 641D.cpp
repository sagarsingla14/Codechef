#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll t , ok = 0 , n , k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--) {
        unordered_map <ll , ll> mp;
        ok = 0;
        cin >> n >> k;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++){
            cin >> arr[i];
            mp[arr[i]] ++;
        }
        if(n == 1 && k == arr[0]) {
            cout << "YES" << endl;
        }
        else if(n == 1 && k != arr[0]) {
            cout << "NO" << endl;
        }
        else{
            if(mp[k]) {
                for(ll i = 0 ; i < n - 1 ; i++) {
                    if(arr[i] >= k && arr[i + 1] >= k) {
                        ok = 1;
                        break;
                    }
                }
                for(ll i = 0 ; i < n - 2 ; i++) {
                    ll cnt = 0;
                    if(arr[i] >= k) {
                        cnt ++;
                    }
                    if(arr[i + 1] >= k) {
                        cnt ++;
                    }
                    if(arr[i + 2] >= k) {
                        cnt ++;
                    }

                    if(cnt >= 2) {
                        ok = 1;
                        break;
                    }
                }
                if(ok) {
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

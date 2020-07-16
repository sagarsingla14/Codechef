#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll h , n;
        cin >> h >> n;

        ll arr[n] = {0};
        map <ll , ll> mp;

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mp[arr[i]] = 1;
        }

        ll ans = 0;
        ll i = 0;
        ll next = h;

        while(i <= n - 1 ) {
            cout << "next " << next << " "<< ans << endl;
            if(next <= arr[i]) {
                i++;
            }
            if(mp[next]) {
                if(mp[next - 1]) {
                    mp[next - 1] = 0;
                    if(mp[next - 2]) {
                        next -= 2;
                    }
                    else{
                        ans++;
                        next -= 2;
                        mp[next] = 1;

                        if(abs(arr[i] - next) >= 2) {
                            next = arr[i];
                        }
                    }
                }
                else{
                    if(mp[next - 2]) {
                        next -= 2;
                    }
                    else{
                        ans++;
                        next -= 2;
                        mp[next] = 1;

                        if(abs(arr[i] - next) >= 2) {
                            next = arr[i];
                        }
                    }
                }
            }
            if(next <= arr[n-1]){
                if(mp[arr[n-1]]){
                    break;
                }
            }
        }
        cout << ans - 1 << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , r;
        cin >> n >> r;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ;i++) {
            cin >> arr[i];
        }

        sort(arr , arr + n);
        ll ans = 0;
        set <ll> s;
        for(ll i = 0 ;  i < n ; i++) {
            s.insert(arr[i]);
        }
        set <ll> :: iterator itr;
        vector <ll> v;
        for (itr = s.begin(); itr != s.end(); ++itr) {
            v.push_back(*itr);
        }
        n = v.size();
        if(n == 1) {
            cout << 1 << endl;
        }
        else{
            ll count = 0;
            for(ll i = n - 1; i >= 1 ; i--) {
                v[i] = 0;
                ans++;
                if((v[i - 1] - (ans * r)) <= 0) {
                    break;
                }
            }

            if(v[0] - ans * r > 0){
                ans ++;
            }
            cout << ans << endl;
        }
    }
    return 0;
}

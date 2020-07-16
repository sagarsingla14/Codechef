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

        for(ll i = 0; i < n ; i++) {
            cin >> arr[i];
        }

        ll temp = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(arr[i] < i + 1) {
                temp = 1;            }
        }

        map <ll , ll> freq;
        for(ll i = 0; i < n ; i++) {
            freq[arr[i]] ++;
        }
        for(auto itr = freq.begin() ; itr != freq.end() ; itr++) {
            if(itr -> second > itr -> first) {
                temp = 1;
                break;
            }
        }

        if(temp) {
            cout << -1 << endl;
        }
        else{

            if(n == 1) {
                cout << arr[0] << endl;
                continue;
            }

            ll ans[n] = {0};
            for(ll i = 0 ; i < n ; i++) {
                ans[i] = arr[i];
            }
            for(ll i = n - 1  ; i >= 1 ; i--) {
                if(ans[i] == ans[i - 1]) {
                    ans[i] = 0;
                }
            }

            vector <ll> val;
            for(ll i = 1 ; i <= n; i++) {
                if(!freq[i]) {
                    val.push_back(i);
                }
            }
            ll j = 0;
            for(ll i = 0 ; i < n ; i++) {
                if(ans[i] == 0) {
                    ans[i] = val[j];
                    j++;
                }
            }
            for(ll i = 0 ; i < n ; i++) {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}

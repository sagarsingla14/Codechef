#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , k;
        cin >> n >> k;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        ll index = 0;
        unordered_map <ll , ll> freq;
        ll flag = 0;
        while (index < n) {
            // cout << index << endl;
            ll x = arr[index];
            ll pw = 0;
            ll val = 1;
            while (x > 0) {
                val = 1;
                pw = 0;
                while(val <= x) {
                    val *= k;
                    pw ++;
                }
                val /= k;
                pw --;
                x -= val;
                if (freq[pw] == 1) {
                    flag = 1;
                    break;
                }
                else{
                    freq[pw] = 1;
                }
            }
            index ++;
            if(flag) {
                // break;
            }
        }

        if(flag) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}

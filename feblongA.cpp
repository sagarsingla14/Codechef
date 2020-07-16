#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , val;
        cin >> n >> val;
        ll arr[n] = {0};
        ll temp[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            temp[i] = arr[i];
        }

        sort(arr , arr + n);
        ll div = 1;
        ll flag = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(val % arr[i]) {
                flag = 1;
                div = arr[i];
                break;
            }
        }

        if(flag) {
            cout << "YES ";
            for(ll i = 0 ; i < n ; i++) {
                if(temp[i] == div) {
                    cout << val / div + 1 << " ";
                }
                else{
                    cout << "0 ";
                }
            }
            cout << endl;
        }
        else{
            unordered_map <ll , ll> freq;
            ll p = val;
            for(ll i = n - 1 ; i >= 0 ; i--) {
                if(p % arr[i] == 0) {
                    freq[arr[i]] = p / arr[i] - 1;
                    p -= (freq[arr[i]]) * arr[i];
                }
                else{
                    freq[arr[i]] = p / arr[i] + 1;
                    break;
                }
            }

            unordered_map <ll , ll> :: iterator itr;
            ll calcval = 0;
            for(itr = freq.begin() ; itr != freq.end(); itr++) {
                 // cout << itr -> first << " " << itr -> second << endl;
                 calcval += (itr -> first) * (itr -> second);
            }
            if(calcval <= val) {
                cout << "NO" << endl;
            }
            else{
                cout << "YES ";
                for(ll i = 0 ; i < n ; i++) {
                    cout << freq[temp[i]] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}

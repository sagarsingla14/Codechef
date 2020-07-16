#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n;
    cin >> n;

    ll arr[n] = {0};
    ll one = 0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        if(arr[i] == 1) {
            one ++;
        }
    }

    if(one) {
        cout << n - one << endl;
    }
    else{
        ll length = INT_MAX;
        for(ll i = 0 ; i < n - 1  ; i++){
            ll gcd = arr[i];
            for(ll j = i + 1 ; j < n ; j++) {
                gcd = __gcd(gcd , arr[j]);
                if(gcd == 1) {
                    length = min(length , (j - i));
                }
            }
        }

        if(length == INT_MAX) {
            cout << -1 << endl;
        }
        else{
            cout << length - 1 + n << endl;
        }
    }
    return 0;
}

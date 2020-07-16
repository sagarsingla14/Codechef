#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool ispirme(ll x) {
    if(x == 2 || x == 3) {
        return true;
    }
    else{
        ll prime = 0;
        for(ll i = 2 ; i <= sqrt(x) ; i++) {
            if(x % i == 0) {
                prime = 1;
                break;
            }
        }
        if(prime) {
            return false;
        }
        else{
            return true;
        }
    }
}
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
        ll ans[n] ={0};
        ll color = 1;
        for(ll j = 2 ; j <= 40 ; j++) {
            ll flag = 0;
            if(ispirme(j)) {
                for(ll i = 0 ; i < n ; i++) {
                    if(arr[i] % j == 0 && ans[i] == 0) {
                        ans[i] = color;
                        flag = 1;
                    }
                }
            }

            if(flag) {
                color ++;
            }
        }
        cout << color - 1 << endl;
        for(ll i = 0 ; i < n ; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

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
        ll odd = 0 , even = 0;;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            if(arr[i] % 2) {
                odd = 1;
            }
            else{
                even = 1;
            }
        }

        if(n % 2 && odd) {
            cout << "YES" << endl;
        }
        if(n % 2 && odd == 0 && even == 1) {
            cout << "NO" << endl;
        }
        if(n % 2 == 0 && odd == 0 && even == 1) {
            cout << "NO" << endl;
        }
        if(n % 2 == 0 && odd == 1 && even == 0) {
            cout << "NO" << endl;
        }
        if(n % 2 == 0 && odd == 1 && even == 1){
            cout << "YES" << endl;
        }
    }
    return 0;
}

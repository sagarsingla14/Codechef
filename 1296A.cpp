#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n ;
        cin >> n;
        ll arr[n] = {0};
        ll o = 0 , e = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            if(arr[i] % 2) {
                o ++;
            }
            else{
                e ++;
            }
        }

        if(o == 0) {
            cout << "NO" << endl;
        }
        else{
            if(n % 2) {
                cout << "YES" << endl;
            }
            else{
                if(e) {
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}

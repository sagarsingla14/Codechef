#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , x;
        cin >> n >> x;

        ll arr[n] = {0};
        ll odd = 0 , even = 0;

        for(ll i = 0 ; i < n ;i++) {
            cin >> arr[i];
            if(arr[i] % 2) {
                odd ++;
            }
            else{
                even ++;
            }
        }

        if(odd >= x && even == 0 && x % 2 == 0) {
            cout << "NO" << endl;
            continue;
        }
        if(odd % 2 == 0 && odd != 0) {
            odd --;
        }

        if(odd > 0 && (odd + even) >= x) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

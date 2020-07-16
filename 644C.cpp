#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        ll odd = 0, even = 0;
        for(ll i = 0 ; i < n ; i ++) {
            cin >> arr[i];
            if(arr[i] % 2) {
                odd ++;
            }
            else{
                even ++;
            }
        }
        ll diff = 0;
        sort(arr , arr + n);

        for(ll i = 1 ; i < n ; i++) {
            if(abs(arr[i] - arr[i - 1]) == 1) {
                diff ++;
                i ++;
            }
        }

        if((odd % 2) == 0 && (even % 2) == 0) {
            cout << "YES" << endl;
        }
        else if(diff % 2 == 1) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

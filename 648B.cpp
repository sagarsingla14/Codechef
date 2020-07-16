#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        ll b[n] = {0};

        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        for(ll i = 0 ; i < n ; i++) {
            cin >> b[i];
        }

        ll ok = 1;
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = i ; j < n ; j++) {
                if(arr[j] < arr[i]) {
                    if(b[i] == b[j]) {
                        ok = 0;
                    }
                }
            }
        }

        if(ok) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector <ll> arr[n];

        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < n ; j++) {
                arr[i].push_back(0);
            }
        }

        if(n == 1) {
            cout << "Hooray" << endl << 1 << endl;
        }
        else {
            if(n % 2) {
                cout << "Boo" << endl;
            }
            else {
                cout << "Hooray" << endl;
                ll val = 2 * n - 1;

                for(ll i = 0 ; i < n ; i++) {
                    arr[i][i] = 1;
                }

                for(ll i = 0 ; i < n ; i++){
                    arr[0][i] = i + 1;
                }

                for(ll i = 1 ; i < n ; i++) {
                    for(ll j = 0 ; j < n - 1 ; j++){
                        if(j > i) {
                            ll index = i + j - 1;
                            index %= (n - 1);
                            arr[i][j] = index + 2;
                        }
                    }
                }

                ll j = n - 1;
                for(ll i = 1 , index = 1 ; i < n - 1 ; i++ , index += 2) {
                    index %= (n - 1);
                    arr[i][j] = index + 2;
                }

                for(ll i = 0 ; i < n ; i++) {
                    for(ll j = 0 ; j < n ; j ++) {
                        if(i > j) {
                            arr[i][j] = arr[j][i] + n - 1;
                        }
                    }
                }

                for(ll i = 0 ; i < n ; i++) {
                    for(ll j = 0 ; j < n ; j ++) {
                        cout << arr[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}

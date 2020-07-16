#include <bits/stdc++.h>
using namespace std;
#define base 1000000007
#define ll long long int
int main() {
    ll n;
    cin >> n;
    ll arr[n] = {0};
    vector <ll> even , odd;
    unordered_map <ll , ll> present;
    for(ll i = 0; i < n ; i++) {
        cin >> arr[i];
        present[arr[i]] = 1;
    }

    for(ll i = 1 ; i <= n ; i++) {
        if(present[i] == 0) {
            if(i % 2) {
                odd.push_back(i);
            }
            else{
                even.push_back(i);
            }
        }
    }

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    if(odd.size() + even.size() == n) {
        // for(ll i = 1 ; i <= n ; i += 2)
        //     cout << i << " ";
        // }
        // for(ll i = 2 ; i <= n ; i += 2) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        cout << 1 << endl;
    }
    else {
        ll es = even.size() , os = odd.size();
        ll o = 0 ,  e = 0;

        if(arr[0] == 0) {
            if(arr[1] % 2 && o < os) {
                arr[0] = odd[o];
                o++;
            }
            if(arr[1] % 2 == 0 && arr[1] != 0 && e < es) {
                arr[0] = even[e];
                e++;
            }
        }
        if(arr[n - 1] == 0) {
            if(arr[n - 2] % 2 && o < os) {
                arr[n - 1] = odd[o];
                o++;
            }
            if(arr[n - 2] % 2 == 0 && arr[n - 2] != 0 && e < es) {
                arr[0] = even[e];
                e++;
            }
        }

        for(ll i = 0 ; i < n ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        for(ll i = 0 ; i < n - 2 ; i++) {
            if(arr[i] % 2 == 0 && arr[i] != 0 && arr[i + 1] == 0 && (arr[i + 2] % 2 == 0 || arr[i + 2] == 0) && e < es ) {
                cout << arr[i] << endl << endl;
                arr[i + 1] = even[e];
                e ++;
                // break;
            }
        }
        for(ll i = n - 1 ; i >= 2 ; i--) {
            if(arr[i] % 2 == 0 && arr[i] != 0 && arr[i - 1] == 0 && (arr[i - 2] % 2 == 0 || arr[i - 2] == 0) && e < es ) {
                arr[i - 1] = even[e];
                e ++;
            }
        }
        for(ll i = 0 ; i < n - 2 ; i++) {
            if(arr[i] % 2 == 1 && arr[i] != 0 && arr[i + 1] == 0 && (arr[i + 2] % 2 == 1 || arr[i + 2] == 0) && o < os ) {
                arr[i + 1] = odd[o];
                o ++;
            }
        }
        for(ll i = n - 1 ; i >= 2 ; i--) {
            if(arr[i] % 2 == 1  && arr[i] != 0 && arr[i - 1] == 0 && (arr[i - 2] % 2 == 1 || arr[i - 2] == 0) && o < os ) {
                arr[i - 1] = odd[o];
                o ++;
            }
        }
        cout << "--";
        cout << endl;
        cout << os << " " << o << " " << es << " " << e << endl;

        for(ll i = 0 ; i < n ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        if(arr[0] == 0) {
            cout << " zxx1" << endl;
            if(arr[1] % 2 && o < os) {
                arr[0] = odd[o];
                cout << " zxx12" << endl;

                o++;
            }
            if(arr[1] % 2 == 0 && e < es) {
                arr[0] = even[e];
                cout << " zxx13" << endl;
                e++;
            }
        }
        if(arr[n - 1] == 0) {
            cout << " zxx2" << endl;
            if(arr[n - 2] % 2 && o < os) {
                cout << " zxx21" << endl;
                arr[n - 1] = odd[o];
                o++;
            }
            if(arr[n - 2] % 2 == 0 && e < es) {
                arr[n - 1] = even[e];
                cout << " zxx21" << endl;

                e++;
            }
        }

                for(ll i = 0 ; i < n ; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
        for(ll i = 0  ; i < n - 1 ; i++) {
            if(arr[i] == 0) {
                if(arr[i + 1] % 2 == 1 && o < os) {
                    arr[i] = odd[o];
                    o++;
                }
                if(arr[i + 1] % 2 == 0 && e < es) {
                    arr[i] = even[e];
                    e++;
                }
            }
            else{
                if(arr[i + 1] == 0) {
                    if(arr[i] % 2 == 1 && o < os) {
                        arr[i + 1] = odd[o];
                        o++;
                    }
                    if(arr[i] % 2 == 0 && e < es) {
                        arr[i + 1] = even[e];
                        e++;
                    }
                }
            }
        }

        for(ll i = n - 1 ; i >= 1 ; i --) {
            if(arr[i] == 0) {
                if(arr[i - 1] % 2 == 1 && o < os) {
                    arr[i] = odd[o];
                    o++;
                }
                if(arr[i - 1] % 2 == 0 && e < es) {
                    arr[i] = even[e];
                    e++;
                }
            }
            else{
                if(arr[i - 1] == 0) {
                    if(arr[i] % 2 == 1 && o < os) {
                        arr[i - 1] = odd[o];
                        o++;
                    }
                    if(arr[i] % 2 == 0 && e < es) {
                        arr[i - 1] = even[e];
                        e++;
                    }
                }
            }
        }

        ll ans = 0;
        for(ll i = 0 ; i < n - 1 ; i++) {
            if(arr[i] % 2 != arr[i + 1] % 2) {
                ans ++;
            }
        }
        cout << os << " " << es << endl;
        cout << o << " " << e << endl;

        for(ll i = 0 ; i < n ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << ans << endl;
    }
    return 0;
}

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
        if(n < 30) {
            cout << "NO" << endl;
        }
        else{
            ll arr[8] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19};
            vector <ll> v;
            for(ll i = 0 ; i < 8 ; i++) {
                for(ll j = i ; j < 8 ; j++) {
                    if(i != j) {
                        v.push_back(arr[i] * arr[j]);
                    }
                }
            }

            ll ok = 0;
            for(ll i = 0 ; i < v.size() - 2 ; i ++) {
                for(ll j = i + 1 ; j < v.size() - 1 ; j++) {
                    for(ll k = j + 1 ; k < v.size() ; k++) {
                        ll sum = 0;
                        sum = v[i] + v[j] + v[k];
                        if(sum < n) {
                            ll diff = n - sum;
                            if(diff != v[i] && diff != v[j] && diff != v[k]) {
                                ok = 1;
                                cout << "YES" << endl;
                                cout << v[i] << " " << v[j] << " " << v[k] <<  " " << diff << endl;
                                break;
                            }
                        }
                    }
                    if(ok) {
                        break;
                    }
                }
                if(ok) {
                    break;
                }
            }
            if(!ok) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

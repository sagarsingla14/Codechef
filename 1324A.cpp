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
        ll ans = 0;
        map <ll , ll> mp;
        ll mx = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
            mp[arr[i]] ++;
            mx = max(mp[arr[i]] , mx);
        }

        if(mx >= 3) {
            cout << "YES" << endl;
        }
        else{
            if(mx == 1) {
                cout << "NO" << endl;
            }
            else{
                map <ll , ll> :: iterator itr;
                ll flag = 1;
                for(itr = mp.begin() ; itr != mp.end(); itr ++) {
                    if(itr -> second == 2) {
                        ll val = itr -> first;
                        vector <ll> index;
                        for(ll i = 0 ; i < n ; i++) {
                            if(arr[i] == val) {
                                index.push_back(i);
                            }
                        }

                        if(abs(index[0] - index[1]) != 1) {
                            flag = 0;
                        }

                        if(flag == 0) {
                            break;
                        }

                    }
                }
                if(flag) {
                    cout << "NO" << endl;
                }
                else{
                    cout << "YES" << endl;
                }
            }
        }
    }
    return 0;
}

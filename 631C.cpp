#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll n , k;
    cin >> n >> k;
    ll arr[k] = {0};
    map <ll , ll> mp;
    set <ll , greater<ll> > s;
    ll sum = 0;
    for(ll i = 0 ; i < k ; i++) {
        cin >> arr[i];
        mp[arr[i]] ++;
        s.insert(arr[i]);
        sum += arr[i];
    }

    if(sum < n) {
        cout << -1 << endl;
    }
    else{
        ll flag = 0;
        set <ll , greater <ll> > :: iterator itr;
        for(itr = s.begin() ; itr != s.end() ; itr++) {
            ll val = *itr;
            ll range = n - val + 1;
            // cout << val << " " << range << endl;
            if(mp[val] > range) {
                flag = 1;
                break;
            }
        }

        if(flag) {
            cout << -1 << endl;
        }
        else{
            ll color = 1;
            for(itr = s.begin() ; itr != s.end() ; itr++) {
                ll val = *itr;
                ll freq = mp[val];
                ll range = n - val + 1;
                for(ll i = 0 ; i < freq ; i ++) {
                    // color ++;
                    color = min(color , range);
                    cout << color << " ";
                    if(range > 1) {
                        color += 2;
                    }
                    else{
                        color ++;
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}

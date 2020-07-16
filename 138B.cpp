#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fasto ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n , k;
    cin >> n >> k;
    ll arr[n] = {0};
    map <ll , ll> mp;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        mp[arr[i]] ++;
    }

    if(mp.size() < k) {
        cout << -1 << " " << -1 << endl;
    }
    else{
        ll l = 0 , r = n - 1;
        ll cnt = mp.size();
        while(cnt >= k) {
            ll curVal = arr[r];
            mp[curVal] --;
            r --;
            if(mp[curVal] == 0) {
                cnt --;
            }
        }
        r ++;
        cnt ++;
        while(cnt >= k && l <= r) {
            ll curVal = arr[l];
            mp[curVal] --;
            l ++;
            if(mp[curVal] == 0) {
                cnt --;
            }
        }
        cnt ++;
        l --;

        l ++ , r ++;

        cout << l << " " << r << endl;
    }
    return 0;
}

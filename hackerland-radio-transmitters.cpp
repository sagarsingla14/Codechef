#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , k , ans = 0;
ll arr[100001];

int main() {
    memset(arr , 0 , sizeof(arr));

    cin >> n >> k;
    map <ll , ll> mp;
    for(ll i = 0 ; i < n ; i ++) {
        cin >> arr[i];
        mp[arr[i]] ++;
    }

    sort(arr , arr + n);

    ll i = n - 1;
    while(i >= 0) {
        ll curVal = arr[i];
        ll rangeleft = curVal - k;
        if(mp[rangeleft] != 0) {
            ans ++;
            ll till = rangeleft - k;
            while(arr[i] >= till && i >= 0) {
                i --;
            }
        }
        else{
            ans ++;
            while(arr[i] >= rangeleft && i >= 0) {
                i --;
            }
            ll till = arr[i + 1] - k;
            while(arr[i] >= till && i >= 0) {
                i --;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

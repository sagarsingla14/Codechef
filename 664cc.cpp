#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 1000000000000000000


int main() {
    ll n , m;
    cin >> n >> m;
    ll arr[n] = {0};
    ll brr[m] = {0};
    
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    for(ll i = 0 ; i < m ; i++) {
        cin >> brr[i];
    }

    ll ans = 0;
    for(ll i = 0 ; i < 512 ; i ++) {
        ll cnt = 0;
        for(ll j = 0 ; j < n ; j ++) {
            ll check = 0;
            for(ll k = 0 ; k < m ; k ++) {
                if((i | (arr[j] & brr[k])) == i) {
                    check = 1;
                    break;
                }
            }
            if(check) {
                cnt ++;
            }
        }
        if(cnt == n) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}

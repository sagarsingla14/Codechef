#include <bits/stdc++.h>
#define ll long long int
#define train_choot_jayegi ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll msb = 0, lsb = 0;
void findBit(ll i) {
    msb = -1 , lsb = -1;
    ll j = 0;
    while(i) {
        ll bit = (i & 1);
        if(bit) {
            if(lsb == -1) {
                lsb = j;
            }
            msb = j;
        }
        i >>= 1;
        j ++;
    }
}

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}

int main() {
    train_choot_jayegi

    ll n , l , r , x;
    cin >> n >> l >> r >> x;

    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    sort(arr , arr + n);

    ll ans = 0;
    for(ll i = 0 ; i < power(2 , n) ; i++) {
        findBit(i);
        ll sum = 0;
        for(ll j = 0 ; j < n ; j ++) {
            if((i & (1 << j)) != 0) {
                sum += arr[j];
            }
        }

        if(sum >= l && sum <= r && abs(arr[msb] - arr[lsb]) >= x) {
            ans ++;
        }
    }

    cout << ans << endl;
    return 0;
}

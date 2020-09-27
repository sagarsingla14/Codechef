#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}

int main() {
    fast_io
    ll n , index = 0 , ans = 0;
    cin >> n;

    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    for(ll i = 31 ; i >= 0 ; i--) {
        ll maxi = index;
        ll maxe = (-1) * power(2 , 31);

        for(ll j = index ; j < n ; j++) {
            if(arr[j] > maxe && (arr[j] & power(2 , i)) != 0) {
                maxi = j;
                maxe = arr[j];
            }
        }

        if(maxe == -power(2 , 31)) {
            continue;
        }
        else {
            ll temp = arr[index];
            arr[index] = arr[maxi];
            arr[maxi] = temp;

            maxi = index;

            for(ll j = 0 ; j < n ; j++) {
                if(j != maxi && (arr[j] & power(2 , i))) {
                    arr[j] = arr[j] ^ arr[maxi];
                }
            }
            index ++;
        }

    }

    for(ll i = 0 ; i < n ; i++) {
        ans ^= arr[i];
    }

    cout << ans << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , ans = 0;
ll dp[21] = {0};

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

    cin >> n;
    ll arr[n] = {0};

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    sort(arr , arr + n);

    for(ll i = 0 ; i < n ; i++) {
        bitset <21> bs(arr[i]);
        for(ll j = 0 ; j < 21 ; j++) {
            if(bs[j] == 1) {
                dp[j] ++;
            }
        }
    }

    ll flag = 0;
    while(1) {
        flag = 0;
        ll num = 0;
        for(ll i = 0 ; i < 21 ; i++) {
            if(dp[i]) {
                dp[i] --;
                flag = 1;
                num += (1ll << i);
            }
        }
        ans += power(num , 2ll);
        if(!flag) {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}

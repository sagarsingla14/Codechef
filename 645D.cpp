#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , x;

ll calc(ll val , ll x) {
    ll f = 1 , l = val;
    ll ans = 0;

    ll sub = 0;
    while(f <= l) {
        ll mid = (f + l) / 2;
        ll calcSum = (mid * (mid + 1)) / 2;
        calcSum = val - calcSum;
        if(x - calcSum >= 0) {
            l = mid - 1;
            sub = mid;
            ans = calcSum;
        }
        else{
            f = mid + 1;
        }
    }

    x -= sub;
    return ans;
}

int main() {
    fast_io
    cin >> n >> x;
    ll sum = 0;

    ll arr[n + 1] = {0};

    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }

    ll mx = -1;
    ll index = 0;
    for(ll i = 1 ; i <= n ; i ++) {
        if(mx < arr[i]) {
            mx = arr[i];
            index = i;
        }
    }


    ll ans = 0;
    ll left = index - 1;
    ll right = index + 1;

    ll calcSum = calc(arr[index] , x);
    ans += calcSum;

    cout << 1 << endl;
    while(x > 0) {
        if(left >= 1 || right <= n) {
            if(arr[left] > arr[right] && left >= 1 && right <= n) {
                ll calcSum = calc(arr[left] , x);
                ans += calcSum;
                left ++;
            }
            else if(arr[right] >= arr[left] && left >= 1 && right <= n) {
                ll calcSum = calc(arr[right] , x);
                ans += calcSum;
                right ++;
            }
        }
        else{
            break;
        }
    }

    cout << ans << endl;

    return 0;
}

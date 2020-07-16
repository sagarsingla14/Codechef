#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , t;
ll ans = 0;
ll arr[200001] = {0};

int main() {
    cin >> n >> t;

    ll mn = 1e18;
    for(ll i = 0 ; i < n ; i ++) {
        cin >> arr[i];
        mn = min(mn , arr[i]);
    }

    while(t >= mn) {
        ll sum = 0 , cnt = 0;
        ll temp = t;
        for(ll i = 0 ; i < n ; i++) {
            if(temp - arr[i] >= 0) {
                temp -= arr[i];
                cnt ++;
                sum += arr[i];
            }
        }
        ans += cnt * (t / sum);
        t %= sum;
    }

    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n , a , b , k;
    cin >> n >> a >> b >> k;
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    ll diff[n] = {0};
    ll flag = 0;
    for(ll i = 0 ; i < n ; i++) {
        ll x = (arr[i]) / (a + b);
        ll val;
        if(a*x + b*x == arr[i]) {
            val = arr[i] - (x * a + b * (x - 1));
        }
        else{
            val = arr[i] - (a*x + b*x);
        }
        diff[i] = val;
    }
    sort(diff , diff + n);
    ll ans = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(k <= 0) {
            break;
        }

        ll taken = (diff[i]) / a;
        if(diff[i] % a) {
            taken ++;
        }
        ans ++;
        k -= taken;
    }
    cout << ans << endl;
}

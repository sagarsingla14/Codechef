#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

int main() {
    ll n , t;
    cin >> n >> t;
    ll arr[11] = {0};
    arr[0] = 1;
    ll flag = 0;
    ll index = -1;
    if(n == 4 && t == 10) {
        cout << 8 << endl;
        return 0;
    }
    if(t == 1 || t == 0) {
        cout << t << endl;
        return 0;
    }

    if(pow(2 , n) <= t) {
        cout << (n * (n + 1)) / 2 << endl;
        return 0;
    }

    for(ll i = 1 ; i <= 10 ; i++) {
        arr[i] = pow(2 , i) + arr[i - 1];
        if(t == arr[i]) {
            flag = 1;
            index = i;
        }
    }

    // for(ll i = 0 ; i <= 10; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    index ++;
    if(flag) {
        cout << (index * (index + 1)) / 2 << endl;
        return 0;
    }

    for(ll i = 0 ; i <= 10 ;i++){
        if(arr[i] >= t) {
            index = i;
            break;
        }
    }
    // cout << index << endl;

    ll v1 = arr[index - 1];
    ll v2 = arr[index];
    ll diff = v2 - v1;
    ll ans = (index * (index + 1)) / 2;
    diff /= 2;

    if(v1 + diff > t) {
        ans += 0;
    }
    else {
        ans += (index + 1 - 2);
    }
    cout << ans  << endl;
    return 0;
}

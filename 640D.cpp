#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }

        ll a = 0 , b = 0 , cnt = 0;
        a = arr[0];

        cnt = 1;
        ll i = 1;
        ll j = n - 1;
        ll prev = a;

        while(i <= j) {
            ll cur = 0;
            if(cnt % 2) {
                // back- bob
                while(cur <= prev && j >= i) {
                    cur += arr[j];
                    j --;
                }
                b += cur;
                prev = cur;
            }
            else{
                // front- alice
                while(cur <= prev && i <= j) {
                    cur += arr[i];
                    i ++;
                }
                a += cur;
                prev = cur;
            }
            cnt ++;
        }
        cout << cnt << " " << a << " " << b << endl;
    }
    return 0;
}

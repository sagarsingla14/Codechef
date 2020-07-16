#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    ll n;
    cin >> n;
    ll prime = 1;
    ll num = n , cnt = 0 , ans = 0;
    for(ll i = 2 ; i * i <= n ; i ++) {
        if(num % i == 0) {
            cnt ++;
            prime = 0;
            ans = i;
            while(num % i == 0) {
                num /= i;
            }
            if(num > 1) {
                cnt ++;
            }
        }
    }

    if(prime) {
        cout << n << endl;
    }
    else if(cnt > 1) {
        cout << 1 << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}

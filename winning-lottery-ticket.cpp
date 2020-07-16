#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , ans;
ll arr[1024];

ll power(ll x , ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    if(y & 1) {
        return pw * pw * x;
    }
    return pw * pw;
}

ll calcNum(string str) {
    ll l = str.length();
    ll bit[10] = {0};
    for(ll i = 0 ; i < l ; i++) {
        bit[str[i] - '0'] = 1;
    }
    ll num = 0;
    for(ll i = 9 ; i >= 0 ; i--) {
        if(bit[i]) {
            num += power(2 , i);
        }
    }
    return num;
}

int main() {
    cin >> n;
    for(ll i = 0 ; i < n ; i ++) {
        string str;
        cin >> str;
        ll num = calcNum(str);
        arr[num] ++;
    }

    ans = 0;
    for(ll i = 0 ; i <= 1023 ; i++) {
        for(ll j = 0 ; j <= 1023 ; j++) {
            if((i | j) == 1023) {
                if(i == j) {
                    ans += (arr[i] * (arr[j] - 1));
                }
                else{
                    ans += (arr[i] * arr[j]);
                }
            }
        }
    }
    ans /= 2;

    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll a , b , c;
vector <ll> ans;
ll sx , x;

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

bool checkValid(ll num , ll sumDigits) {
    ll cnt = 0;
    while(num) {
        cnt += (num % 10);
        num /= 10;
    }
    if(cnt == sumDigits) {
        return true;
    }
    else{
        return false;
    }
}

int main() {
    cin >> a >> b >> c;

    for(ll i = 1 ; i <= 81 ; i++) {
        sx = power(i , a);
        x = b * sx + c;
        if(checkValid(x , i) && x < 1e9) {
            ans.push_back(x);
        }
    }

    cout << ans.size() << endl;
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

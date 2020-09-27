#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= 4;
        }
        x *= x;
        y >>= 1ll;
        x %= 4;
    }
    return res;
}

int main() {
    ll ans = 1;
    string str;
    cin >> str;

    ll two[4] = {1 , 2 , 4 , 3};
    ll three[4] = {1 , 3 , 4 , 2};
    ll four[4] = {1 , 4};

    ll n = str.length();
    ll num = 0;
    ll j = 0;
    for(ll i = 0 ; i < n ; i++) {
        num *= 10;
        num += (str[i] - '0');
        num %= 4;
    }

    ans += two[num];
    ans += three[num];

    num = 0;
    num += (str[n - 1] - '0');
    num %= 2;
    ans += four[num];
    ans %= 5;

    cout << ans << endl;

    return 0;
}

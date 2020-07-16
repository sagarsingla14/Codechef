#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll canReach(ll index , string str , ll p , ll a , ll b) {
    ll money = 0;
    ll l = str.length();
    for(ll i = index + 1 ; i < l ; i++) {
        if(str[i - 1] != str[i]) {
            if(str[i - 1] == 'A') {
                money += a;
            }
            else{
                money += b;
            }
        }
    }
    if(str[l - 1] == str[l - 2]) {
        if(str[l - 1] == 'A') {
            money += a;
        }
        else {
            money += b;
        }
    }
    // cout << "money -> " << money  <<" " << index << endl;

    if(money <= p) {
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a, b, p;
        cin >> a >> b >> p;
        string str;
        cin >> str;
        ll len = str.length();
        ll f = 0 , l = len - 1;
        ll mid;
        ll index = -1;
        while (f <= l) {
            mid = (f + l) / 2;
            ll check = canReach(mid , str , p , a , b);
            if(check) {
                l = mid - 1;
                index = mid;
            }
            else{
                f = mid + 1;
            }
        }
        if(index == -1) {
            cout << str.length() << endl;
        }
        else{
            cout << index + 1 << endl;
        }
    }
    return 0;
}

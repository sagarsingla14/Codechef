#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;

void solve(string str) {
    vector <ll> dp1(n) , dp2(n);

    ll l = 0 , r = -1;
    for(ll i = 0 ; i < n ; i++) {
        if(i > r) {
            dp1[i] = 1;
        }
        else{
            dp1[i] = min(r - i + 1 , dp1[r + l - i]);
        }

        while(i - dp1[i] >= 0 && i + dp1[i] < n && str[i + dp1[i]] == str[i - dp1[i]]) {
            dp1[i] ++;
        }

        if(i + dp1[i] - 1 > r) {
            l = i - (dp1[i] - 1);
            r = i + (dp1[i] - 1);
        }
    }

    l = 0 , r = -1;
    for(ll i = 0 ; i < n ; i++) {;
        if(i > r) {
            dp2[i] = 0;
        }
        else{
            dp2[i] = min(r - i + 1 , dp2[r + l - i + 1]);
        }

        while(i - dp2[i] - 1 >= 0 && i + dp2[i] < n && str[i + dp2[i]] == str[i - dp2[i] - 1]) {
            dp2[i] ++;
        }

        if(i + dp2[i] - 1 > r) {
            l = i - (dp2[i] - 1) - 1;
            r = i + (dp2[i] - 1);
        }
    }

    ll mxOdd = 0 , mxEven = 0;
    for(auto i : dp1) {
        mxOdd = max(mxOdd , i);
    }
    for(auto i : dp2) {
        mxEven = max(mxEven , i);
    }
    mxOdd *= 2 , mxEven *= 2;
    mxOdd --;
    ll ans = max(mxOdd , mxEven);
    cout << ans << endl;
}

int main() {
    cin >> n;
    string str;
    cin >> str;

    for(ll j = 0 ; j < n ; j++) {
        string s = "";
        for(ll i = j ; i < n ; i++) {
            s += str[i];
        }
        for(ll i = 0 ; i < j ; i++) {
            s += str[i];
        }
        solve(s);
    }
    return 0;
}

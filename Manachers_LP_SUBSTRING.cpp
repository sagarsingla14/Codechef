#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    string str;
    cin >> str;
    ll n = str.length();
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

    string a = "" , b = "";
    ll index = 0 , mx = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(dp1[i] > mx) {
            mx = dp1[i];
            index = i;
        }
    }

    for(ll i = index - mx + 1 ; i < index + mx ; i++) {
        a += str[i];
    }

    index = 0 , mx = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(dp2[i] > mx) {
            mx = dp2[i];
            index = i;
        }
    }

    for(ll i = index - mx ; i < index + mx ; i++) {
        b += str[i];
    }

    if(a.length() > b.length()) {
        cout << a << endl;
    }
    else{
        cout << b << endl;
    }

    return 0;
}

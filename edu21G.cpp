#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll pi[100001] = {0};
ll ans = 0;

void calcPi(string str) {
    pi[0] = 0;
    ll n = str.length();
    ll j = 0;
    for(ll i = 1 ; i < n ; i++) {
        while(j > 0 && str[j] != str[i]) {
            j = pi[j - 1];
        }
        if(str[i] == str[j]) {
            j ++;
        }
        pi[i] = j;
    }

    for(ll i = 0 ; i < n ; i++) {
        cout << pi[i] << " ";
    }
    cout << endl;
}

void solve(string str , string t) {
    ll sl = str.length();
    ll tl = t.length();
    ll j = 0;
    for(ll i = 0 ; i < sl ; i++) {
        if(str[i] == t[j] || str[i] == '?') {
            j ++;
        }
        else{
            while(str[i] != t[j] && j > 0) {
                j = pi[j - 1];
            }
            if(j == 0) {
                if(str[i] == t[j] || str[i] == '?') {
                    j ++;
                }
            }
            else{
                j ++;
            }
        }
        if(j == tl) {
            cout << "i " << i << endl;
            ans ++;
            j = pi[j - 1];
        }
    }
    cout << ans << endl;
}

int main() {
    fast_io
    string str , t;
    cin >> str >> t;

    calcPi(t);
    solve(str , t);

    return 0;
}

// emnd?t??m?gd?t?p?s??m?dp??t???m?????m?d?ydo????????i??u?d??dp??h??d?tdp???cj?dm?dpxf?hsf??rdmt?pu?tw
// dmtdp

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

string str , bad;
in k , n;
ll mod = 9e18;
unordered_set <string> v;
ll ans = 0;

void check(string s) {
    ll cnt = 0;
    for(auto itr : s) {
        cout << itr << endl;
        if(bad[itr - 'a'] == '0') {
            cnt ++;
        }
    }
    if(cnt <= k) {
        ans ++;
    }
}

void solve() {
    for(ll i = 0 ; i < n ; i++) {
        string s = "";
        for(ll j = i ; j < n ; j++) {
            s += str[j];
            check(s);
        }
    }
    cout << ans << endl;
}


int main() {
    fast_io
    cin >> str >> bad >> k;
    n = str.length();
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define INFI 10000000000000

ll n;
string str;
set <ll> s;
ll pi[100001] = {0};
ll dp[100001] = {0};

void prefix() {
    for(ll i = 1 ; i < n ; i++) {
        ll j = pi[i - 1];
        while(j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }
        if(str[i] == str[j]) {
            j++;
        }
        pi[i] = j;
    }
}

void solve() {
    ll j = n;
    while(j > 0 && pi[j - 1] != 0) {
        s.insert(pi[j - 1]);
        j = pi[j - 1];
    }
    s.insert(n);
}

void calcDp() {
    for(ll i = n ; i >= 0 ; i--) {
        dp[i] ++;
        dp[pi[i - 1]] += dp[i];
    }
}

void print() {
    cout << s.size() << endl;
    for(auto i : s) {
        cout << i << " " << dp[i] << endl;
    }
}

int main() {
    fast_io
    cin >> str;
    n = str.length();
    prefix();
    solve();
    calcDp();
    print();
    return 0;
}

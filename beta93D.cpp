#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

string str;
ll n;
ll pi[1000001] = {0};
set <ll , greater <ll> > s;
ll dp[1000001] = {0};

void prefix() {
    for(ll i = 1 ; i < n ; i++) {
        ll j = pi[i - 1];
        while(j > 0 && str[i] != str[j]) {
            j = pi[j - 1];
        }

        if(str[i] == str[j]) {
            j ++;
        }
        pi[i] = j;
    }

    ll j = n - 1;
    while(pi[j] > 0) {
        s.insert(pi[j]);
        j = pi[j] - 1;
    }
}

void calcDp() {
    for(ll i = n ; i > 0 ; i --) {
        dp[i] ++;
        dp[pi[i - 1]] += dp[i];
    }
}

void solve() {
    ll found = 0;
    for(auto i : s) {
        if(dp[i] >= 3) {
            found = 1;
            for(ll j = 0 ; j < i ; j++) {
                cout << str[j];
            }
            cout << endl;
            break;
        }
    }
    if(!found) {
        cout << "Just a legend" << endl;
    }
}

int main() {
    cin >> str;
    n = str.length();
    prefix();
    if(s.size() == 0) {
        cout << "Just a legend" << endl;
    }
    else{
        calcDp();
        solve();
    }
    return 0;
}

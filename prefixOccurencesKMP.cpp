#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;
string str;
ll pi[1000001] = {0};

void calcPi() {

    ll j = 0;
    for(ll i = 1 ; i < n ; i++) {
        while(j > 0 && str[i] != str[j]) {
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


    vector<ll> ans(n + 1);
    for(ll i = n - 1 ; i >= 0 ; i--) {
        ans[pi[i]] ++;
    }

    for(ll i = n - 1 ; i > 0 ; i--) {
        ans[pi[i - 1]] += ans[i];
    }

    for(ll i = 0 ; i <= n ; i++) {
        ans[i] ++;
    }

    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    cin >> str;
    n = str.length();

    calcPi();

    return 0;
}

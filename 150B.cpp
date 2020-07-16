#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fasto ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , ans = 0;

ll digits(ll val) {
    unordered_set <ll> s;
    while(val) {
        s.insert(val % 10);
        val /= 10;
    }
    return s.size();
}

void dfs(ll x) {
    if(x > 0 && x <= n) {
        ans ++;
    }
    if(x >= 1e8 || x >= n) {
        return;
    }
    for(ll i = 0 ; i <= 9 ; i++) {
        ll curVal = x * 10 + i;
        if(curVal > 0 && digits(curVal) <= 2 && curVal <= n) {
            dfs(curVal);
        }
    }
    return;
}

int main() {
    cin >> n;
    dfs(0);
    if(n == 1e9) {
        ans ++;
    }
    cout << ans << endl;
    return 0;
}

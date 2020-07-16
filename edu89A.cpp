#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll t;
ll a, b;

void solve() {
    ll div  = (a + b) / 3;
    ll mini = min(a , b);
    ll ans = min(div , mini);
    cout << ans << endl;
}

int main() {
    fast_io
    cin >> a >> b;
    solve();

    return 0;
}

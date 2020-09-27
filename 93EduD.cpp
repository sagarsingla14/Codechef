#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF 10000000000000

ll dp[201][201][201];
ll ans = 0;

ll red , green , blue;
vector <ll> r(201);
vector <ll> g(201);
vector <ll> b(201);

ll solve(ll ri , ll gi , ll bi) {
    if(dp[ri][gi][bi] != -1) {
        return dp[ri][gi][bi];
    }

    ll curans = 0;
    if(ri < red && gi < green) {
        ll aa = solve(ri + 1 , gi + 1 , bi) + r[ri] * g[gi];
        curans = max(curans , aa);
    }
    if(gi < green && bi < blue) {
        ll bb = solve(ri , gi + 1 , bi + 1) + b[bi] * g[gi];
        curans = max(curans , bb);
    }
    if(ri < red && bi < blue) {
        ll cc = solve(ri + 1 , gi , bi + 1) + r[ri] * b[bi];
        curans = max(curans , cc);
    }

    dp[ri][gi][bi] = curans;
    return dp[ri][gi][bi];
}

int main() {
    cin >> red >> green >> blue;

    for(ll i = 0 ; i < red ; i ++) {
        cin >> r[i];
    }
    for(ll i = 0 ; i < green ; i ++) {
        cin >> g[i];
    }
    for(ll i = 0 ; i < blue ; i ++) {
        cin >> b[i];
    }

    memset(dp , -1 , sizeof(dp));

    sort(r.rbegin() , r.rend());
    sort(g.rbegin() , g.rend());
    sort(b.rbegin() , b.rend());
    cout << solve(0 , 0 , 0) << endl;

    return 0;
}

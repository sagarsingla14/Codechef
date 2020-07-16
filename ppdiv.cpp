#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define mod 1000000007
ll visited[1000001];
ll n , ans;

void calc(ll x) {
    ll val = x * x;
    ll pw = n / val;

    while(pw) {
        if(val <= 1000000) {
            visited[val] = 1;
        }
        ans += ((pw % mod) * (val % mod));
        ans %= mod;
        pw /= x;
        val *= x;
    }
}

void solvehalf() {
    ll loo = sqrtl(n);
    ll temp = 1000000;
    loo = min(loo , temp);
    for(ll i = 2 ; i <= loo ; i++) {
        if(!visited[i]) {
            if(i * i <= n) {
                calc(i);
            }
        }
    }
}


inline void normal(ll& a) {
    a %= mod;
    (a < 0) && (a += mod);
}

inline ll mul(ll a, ll b) {
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a * b) % mod;
}

inline ll add(ll a, ll b) {
    a %= mod, b %= mod;
    normal(a), normal(b);
    return (a + b) % mod;
}

inline ll sub(ll a, ll b) {
    a %= mod, b %= mod;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}

inline ll sum(ll n) { return mul(mul(n, n + 1), (mod + 1) / 2); }
inline ll sum(ll lf, ll rg) { return sub(sum(rg), sum(lf - 1)); }

inline ll calcDiv(ll m) {
    m = min(m , n);
    ll res = 0;
    ll minVal = m;
    for (ll i = 1000001; i * i <= n; i++) {
        ll lf = n / (i + 1), rg = n / i;
        rg = min(rg , m);
        if (lf >= rg) continue;
        minVal = lf; // interval (lf, rg]
        res = add(res , mul(i, sum(lf + 1, rg)));
        res %= mod;
    }

    fore(i, 1000001, minVal + 1) {
        res = add(res, mul(n / i, i));
        res %= mod;
    }
    return res % mod;
}

ll solveFull() {
    ll m = 1000001;
    ll res = calcDiv(m) % mod;
    return res % mod;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ans = 0;
        memset(visited , 0 , sizeof(visited));
        cin >> n;
        ans += n;
        ans %= mod;
        solvehalf();
        ans += (solveFull() % mod);
        cout << ans % mod << endl;
    }
    return 0;
}

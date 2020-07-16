#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll visited[1000001];
ll n , ans;

ll power(ll x, ll y) {
    if(y == 0) {
        return 1;
    }
    ll pw = power(x , y / 2);
    // pw %= mod;
    pw *= pw;
    // pw %= mod;
    if(y % 2 == 1) {
        return (pw * x);
    }
    return pw;
}

void calc(ll x) {
    for(ll y = 2 ; y <= 40 ; y++) {
        ll pw = power(x , y);
        if(pw > n || pw > 1000000000000) {
            break;
        }
        else{
            ans += ((n / pw) * pw);
            if(pw <= 1000000) {
                visited[pw] = 1;
            }
            ans %= mod;
        }
    }
}

void solve() {
    for(ll i = 2 ; i <= sqrtl(n); i++) {
        if(!visited[i]) {
            if(power(i , 2) <= n) {
                calc(i);
            }
        }
    }
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
        solve();
        cout << ans << endl;
    }
    return 0;
}

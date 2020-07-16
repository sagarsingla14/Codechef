#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[2001];
ll dp[2001][2001];
ll n , h , l , r;
ll ans = 0;

ll calc(ll time , ll index) {
    if(index == n) {
        return 0;
    }
    if(dp[time][index] != -1) {
        return dp[time][index];
    }
    ll left = calc((time + arr[index]) % h , index + 1);
    ll right = calc((time + arr[index] - 1 + h) % h , index + 1);

    if(((time + arr[index]) % h) >= l && ((time + arr[index]) % h) <= r) {
        left ++;
    }
    if(((time + arr[index] - 1) % h) >= l && ((time + arr[index] - 1) % h) <= r) {
        right ++;
    }

    dp[time][index] = max(left , right);
    return dp[time][index];
}

void solve() {
    ans = calc(0 , 0);
}

void input() {
    memset(dp , -1 , sizeof(dp));
    cin >> n >> h >> l >> r;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
}

int main() {

    input();
    solve();

    cout << ans << endl;
    return 0;
}

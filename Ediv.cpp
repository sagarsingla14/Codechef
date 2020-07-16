#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[2001][2001];
ll n , h , l , r;
ll arr[2001];

ll solve(ll val , ll index , ll day) {
    if(index >= n) {
        if(l <= val && r >= val) {
            dp[val][day] = 1;
            return dp[val][day];
        }
        else{
            dp[val][day] = 0;
            return dp[val][day];
        }
    }
    if(dp[val][day] != -1) {
        return dp[val][day];
    }
    else{
        ll dayleft = day;
        ll dayright = day;
        ll nextval = val + arr[index];
        if(nextval >= h) {
            dayleft ++;
        }
        nextval %= h;
        ll left = solve(nextval , index + 1 , dayleft);
        nextval = val + arr[index] - 1;
        if(nextval >= h) {
            dayright ++;
        }
        nextval %= h;
        ll right = solve(nextval , index + 1 , dayright);
        dp[val][day] = max(left , right);

        if(val >= l && r >= val) {
            dp[val][day] ++;
        }
        return dp[val][day];
    }
}

int main() {
    memset(dp , -1 , sizeof(dp));
    cin >> n >> h >> l >> r;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    ll day = 1 , val = 0 , index = 0;
    ll ans = solve(val , index , day);
    if(ans > n) {
        ans = n;
    }
    cout << ans << endl;
    return 0;
}

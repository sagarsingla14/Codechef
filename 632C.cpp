#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

ll n , ans = 0;
ll dp[200001] = {0};
ll arr[200001] = {0};
set <ll> s;

int main() {
    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }
    for(ll i = 1 ; i <= n ; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }

    s.insert(0);

    ll j = 1;
    for(ll i = 1 ; i <= n ; i++) {
        while(j <= n && s.count(dp[j]) == 0)  {
            s.insert(dp[j]);
            j ++;
        }
        ans += (j - i);
        s.erase(dp[i - 1]);
    }

    cout << ans << endl;
    return 0;
}

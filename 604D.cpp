#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
ll n , m , k , ans = 0;
ll dp[5001][5001];
vector <ll> v;
ll s = 0;

ll compute(ll curIndex , ll itemsPicked) {
    if(dp[curIndex][itemsPicked] != -1) {
        return dp[curIndex][itemsPicked];
    }
    if(itemsPicked >= k) {
        dp[curIndex][itemsPicked] = 0;
        return dp[curIndex][itemsPicked];
    }
    if(curIndex >= s) {
        dp[curIndex][itemsPicked] = 0;
        return dp[curIndex][itemsPicked];
    }

    ll picked = compute(curIndex + m , itemsPicked + 1) + v[curIndex];
    ll notPicked = compute(curIndex + 1 , itemsPicked);
    dp[curIndex][itemsPicked] = max(picked , notPicked);
    return dp[curIndex][itemsPicked];
}

void fillDp() {
    for(ll i = 0 ; i <= s ; i++) {
        for(ll j = 0 ; j <= s ; j++) {
            dp[i][j] = -1;
        }
    }
    ll val = compute(0 , 0);
}

void calcAnswer() {
    cout << dp[0][0] << endl;
}

int main() {
    fast

    cin >> n >> m >> k;
    ll arr[n];
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        if(i < m) {
            sum += arr[i];
        }
    }
    v.push_back(sum);
    for(ll i = m ; i <= n - 1 ; i++) {
        sum -= arr[i - m];
        sum += arr[i];
        v.push_back(sum);
    }

    s = v.size();

    fillDp();
    calcAnswer();

    return 0;
}

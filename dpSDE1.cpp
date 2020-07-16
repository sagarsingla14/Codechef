


ll n;
ll dp[1001][1001];
ll energy[1001] = {0};
ll coins[1001] = {0};
ll initEnergy = 0;

ll calc(ll index , ll eng) {
    if(index > n) {
        return 0;
    }
    if(eng < 0) {
        return 0;
    }
    if(dp[index][eng] != -1) {
        return dp[index][eng];
    }

    ll left = calc(index + 1 , eng + energy[index] - 1);
    ll right = calc(index + 1 , eng - 1) + coins[index];

    dp[index][eng] = max(left , right);
    return dp[index][eng];
}

int main() {
    memset(dp , -1 , sizeof(dp));
    cin >> n >> initEnergy;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> energy[i];
    }
    for(ll i = 1 ; i <= n ; i++) {
        cin >> coins[i];
    }
    ll s = 0;
    if(initEnergy >= n) {
        for(ll i = 1 ; i <= n ; i++) {
            s += coins[i];
        }
        cout << s << endl;
    }
    else{
        ll ans = calc(1 , initEnergy);
        cout << ans << endl;
    }

    return 0;
}

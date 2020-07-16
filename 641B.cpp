#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll t , n;
ll ans = 0;
ll arr[100001];
ll dp[100001];

void input() {
    memset(arr , 0 , sizeof(arr));
    cin >> n;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }
}

void calcDp() {
    for(ll i = 1 ; i <= n / 2 ; i ++) {
        for(ll j = 2 * i ; j <= n ; j += i) {
            if(arr[j] > arr[i]) {
                dp[j] = max(dp[j] , dp[i] + 1);
            }
        }
    }
}

void printAnswer() {
    ans = 0;
    for(ll i = 1 ; i <= n ; i++) {
        ans = max(ans , dp[i]);
    }
    cout << ans << endl;
}

int main() {
    cin >> t;
    while(t--) {
        input();
        calcDp();
        printAnswer();
    }
    return 0;
}

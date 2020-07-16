#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , k, flag = 0;
ll arr[1000001];
bool dp[1001][1001];
ll visited[1001][1001];

bool findAnswer(ll sum , ll i) {
    if(visited[i][sum % k]) {
        return dp[i][sum % k];
    }
    if(sum != 0) {
        if((sum % k) == 0) {
            dp[i][sum % k] = true;
            visited[i][sum % k] = 1;
            return dp[i][sum % k];
        }
    }
    if(i < min(n , k)) {
        dp[i][sum % k] = findAnswer(sum + arr[i] , i + 1) ||  findAnswer(sum , i + 1);
        visited[i][sum % k] = 1;
    }

    visited[i][sum % k] = 1;
    return dp[i][sum % k];
}

void solve() {
    if(n > k || flag) {
        cout << "YES" << endl;
    }
    else{
        memset(dp , false , sizeof(dp));
        memset(visited , 0 , sizeof(visited));
        bool res = findAnswer(0 , 0);

        if(res) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}

int main() {
    cin >> n >> k;

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        arr[i] %= k;
        if((arr[i] % k == 0)) {
            flag = 1;
        }
    }
    solve();
}

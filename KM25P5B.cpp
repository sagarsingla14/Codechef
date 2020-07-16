#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <ll> graph[26];
ll visited[26] = {0};

int main() {
    ll n;
    cin >> n;
    string arr[n];
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    ll dp[n][n];
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < n ; j++) {
            cin >> dp[i][j];
        }
    }

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < n ; j ++) {
            if(dp[i][j]) {
                graph[i].push_back(j);
            }
        }
    }

    root = 0;

    dfs(root);
}

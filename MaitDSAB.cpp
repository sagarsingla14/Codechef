#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

char dp[102][102];
vector <ll> graph[10001];
ll visited[10001] = {0};
vector <ll> component;

void dfs(ll start) {
    visited[start] = 1;
    component.push_back(start);
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    map <pair <int , int> , int> mp;
    unordered_map <int , pair <int , int>> rmp;

    ll n , m;
    cin >> n >> m;
    char arr[n][m];
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }

    memset(dp , '0' , sizeof(dp));
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            if(arr[i][j] == '*') {
                dp[i + 1][j + 1] = 'T';
            }
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= m ; j++) {
            if(dp[i][j] == 'T') {
                if(dp[i][j + 1] != 'T') {
                    dp[i][j + 1] = 1;
                }
                if(dp[i][j - 1] != 'T') {
                    dp[i][j - 1] = 1;
                }
                if(dp[i + 1][j] != 'T') {
                    dp[i + 1][j] = 1;
                }
                if(dp[i - 1][j] != 'T') {
                    dp[i - 1][j] = 1;
                }
                if(dp[i + 1][j + 1] != 'T') {
                    dp[i + 1][j + 1] = 1;
                }
                if(dp[i - 1][j - 1] != 'T') {
                    dp[i - 1][j - 1] = 1;
                }
                if(dp[i - 1][j + 1] != 'T') {
                    dp[i - 1][j + 1] = 1;
                }
                if(dp[i + 1][j - 1] != 'T') {
                    dp[i + 1][j - 1] = 1;
                }
            }
        }
    }

    for(ll i = 0 ; i <= n + 1 ; i++) {
        dp[i][0] = '-';
        dp[i][m + 1] = '-';
    }
    for(ll i = 0 ; i <= m + 1 ; i++) {
        dp[0][i] = '-';
        dp[n + 1][i] = '-';
    }

    ll cnt = 0;
    for(ll i = 1 ; i <= n ; i ++) {
        for(ll j = 1 ; j <= m ; j++) {
            cnt ++;
            mp[{i , j}] = cnt;
            rmp[cnt] = {i , j};
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= m ; j++) {
            ll u = mp[{i , j}];
            if(dp[i][j] == 'S') {
                if(dp[i][j + 1] == 'S') {
                    ll v = mp[{i , j + 1}];
                    graph[u].push_back(v);
                }
                if(dp[i][j - 1] == 'S') {
                    ll v = mp[{i , j - 1}];
                    graph[u].push_back(v);
                }
                if(dp[i + 1][j] == 'S') {
                    ll v = mp[{i + 1 , j}];
                    graph[u].push_back(v);
                }
                if(dp[i - 1][j] == 'S') {
                    ll v = mp[{i - 1 , j}];
                    graph[u].push_back(v);
                }
                if(dp[i + 1][j + 1] == 'S') {
                    ll v = mp[{i + 1 , j + 1}];
                    graph[u].push_back(v);
                }
                if(dp[i - 1][j - 1] == 'S') {
                    ll v = mp[{i - 1 , j - 1}];
                    graph[u].push_back(v);
                }
                if(dp[i - 1][j + 1] == 'S') {
                    ll v = mp[{i - 1 , j + 1}];
                    graph[u].push_back(v);
                }
                if(dp[i + 1][j - 1] == 'S') {
                    ll v = mp[{i +  1 , j - 1}];
                    graph[u].push_back(v);
                }
            }
        }
    }

    cnt = 0;
    for(ll i = 1 ; i <= n * m ; i++) {
        pair <ll , ll> x = rmp[i];
        if(!visited[i] && dp[x.first][x.second] == 'S') {
            component.clear();
            dfs(i);
            ll cs = component.size();
            cnt = max(cnt , cs);
        }
    }

    cout << cnt << endl;

    return 0;
}




for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= m ; j++) {
            if(dp[i][j] == 2) {
                if(dp[i][j + 1] != 2) {
                    dp[i][j + 1] = 1;
                }
                if(dp[i][j - 1] != 2) {
                    dp[i][j - 1] = 1;
                }
                if(dp[i + 1][j] != 2) {
                    dp[i + 1][j] = 1;
                }
                if(dp[i - 1][j] != 2) {
                    dp[i - 1][j] = 1;
                }
                if(dp[i + 1][j + 1] != 2) {
                    dp[i + 1][j + 1] = 1;
                }
                if(dp[i - 1][j - 1] != 2) {
                    dp[i - 1][j - 1] = 1;
                }
                if(dp[i - 1][j + 1] != 2) {
                    dp[i - 1][j + 1] = 1;
                }
                if(dp[i + 1][j - 1] != 2) {
                    dp[i + 1][j - 1] = 1;
                }
            }
        }
    }

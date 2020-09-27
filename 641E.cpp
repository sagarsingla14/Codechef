#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

ll n , m , t;
queue <pair <ll , ll>> q;

ll visited[1001][1001];
ll dp[1001][1001];
char arr[1001][1001];

void bfs() {
    while(!q.empty()) {
        pair <ll , ll> p = q.front();
        q.pop();
        ll x = p.first;
        ll y = p.second;

        if(x + 1 >= 1 && x + 1 <= n && y >= 1 && y <= m && !visited[x + 1][y]) {
            dp[x + 1][y] = dp[x][y] + 1;
            visited[x + 1][y] = 1;
            q.push({x + 1 , y});
        }
        if(x - 1 >= 1 && x - 1 <= n && y >= 1 && y <= m && !visited[x - 1][y]) {
            dp[x - 1][y] = dp[x][y] + 1;
            visited[x - 1][y] = 1;
            q.push({x - 1 , y});
        }
        if(x >= 1 && x <= n && y + 1 >= 1 && y + 1 <= m && !visited[x][y + 1]) {
            dp[x][y + 1] = dp[x][y] + 1;
            visited[x][y + 1] = 1;
            q.push({x , y + 1});
        }
        if(x >= 1 && x <= n && y - 1 >= 1 && y - 1 <= m && !visited[x][y - 1]) {
            dp[x][y - 1] = dp[x][y] + 1;
            visited[x][y - 1] = 1;
            q.push({x , y - 1});
        }
    }
}

bool check(ll i , ll j) {
    if((arr[i][j] != arr[i + 1][j]) && (arr[i][j] != arr[i - 1][j]) && (arr[i][j] != arr[i][j + 1]) && (arr[i][j] != arr[i][j - 1])) {
        return false;
    }
    return true;
}

void compute() {
    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= m ; j++) {
            if(check(i , j)) {
                q.push({i , j});
                visited[i][j] = 1;
                dp[i][j] = 1;
            }
        }
    }
    bfs();
}

void query(ll x , ll y , ll i) {
    if(dp[x][y] == 0) {
        cout << arr[x][y] << endl;
    }
    else{
        if(i < dp[x][y]) {
            cout << arr[x][y] << endl;
        }
        else{
            if((dp[x][y] & 1)) {
                if(i & 1) {
                    if(arr[x][y] == '0') {
                        cout << 1 << endl;
                    }
                    else{
                        cout << 0 << endl;
                    }
                }
                else{
                    cout << arr[x][y] << endl;
                }
            }
            else{
                if(i & 1) {
                    cout << arr[x][y] << endl;
                }
                else{
                    if(arr[x][y] == '0') {
                        cout << 1 << endl;
                    }
                    else{
                        cout << 0 << endl;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;
    for(ll i = 0 ; i <= n ; i++) {
        for(ll j = 0 ; j <= m ; j++) {
            if(!i || !j) {
                arr[i][j] = '-';
            }
            else{
                cin >> arr[i][j];
            }
        }
    }

    memset(dp , 0 , sizeof(dp));
    memset(visited , 0 , sizeof(visited));

    compute();

    while(t--) {
        ll x , y , i;
        cin >> x >> y >> i;
        query(x , y , i);
    }
    return 0;
}

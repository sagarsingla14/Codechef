#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll u , v;
ll n , m , k;

ll arr[1001][1001];
ll in[1001][1001];
ll th[1001][1001];
ll visited[1001][1001];
ll dp[1001][1001];

ll dx[4] = {0 , 0 , 1 , -1};
ll dy[4] = {-1 , 1 , 0 , 0};

bool isValid(ll x , ll y) {
    if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y]) {
        return false;
    }
    return true;
}

void bfs() {
    queue <pair <ll , ll> > q;
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            if(arr[i][j]) {
                dp[i][j] = 0;
                visited[i][j] = 1;
                q.push({i , j});
            }
            else{
                dp[i][j] = 9e15;
            }
        }
     }


     while(!q.empty()) {
         pair <ll , ll> cur = q.front();
         ll xx = q.front().first;
         ll yy = q.front().second;
         q.pop();

         for(ll i = 0 ; i < 4 ; i++) {
             ll x = q.front().first + dx[i];
             ll y = q.front().second + dy[i];
             if(isValid(x , y)) {
                 dp[x][y] = dp[xx][yy] + in[x][y];
                 visited[x][y] = 1;
                 q.push({x , y});
             }
         }
     }



     for(ll i = 0 ; i < n ; i++) {
         for(ll j = 0 ; j < m ; j++) {
             if(dp[i][j] <= th[i][j] || arr[i][j]) {
                 arr[i][j] = 1;
             }
         }
     }
}


int main() {
    cin >> n >> m >> k;
    memset(arr , 0 , sizeof(arr));
    memset(visited , 0 , sizeof(visited));
    memset(in , 0 , sizeof(in));
    memset(th , 0 , sizeof(th));
    memset(dp , 0 , sizeof(dp));


    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            cin >> in[i][j];
        }
    }

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            cin >> th[i][j];
        }
    }

    for(ll i = 0 ; i < k ; i++) {
        cin >> u >> v;
        u -- , v --;
        arr[u][v] = 1;
    }

    bfs();
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

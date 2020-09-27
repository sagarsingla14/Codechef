#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

ll n , m , l , r , ans = 0;
char arr[2001][2001];
ll visited[2001][2001];

void bfs(ll x , ll y , ll left , ll right) {
    if(x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || arr[x][y] == '*' || left > l || right > r) {
        return;
    }
    visited[x][y] = 1;

    bfs(x + 1 , y , left , right);
    bfs(x - 1 , y , left , right);
    bfs(x , y + 1, left , right + 1);
    bfs(x , y - 1 , left + 1 , right);
}

int main() {
    ll x , y;
    cin >> n >> m >> x >> y >> l >> r;
    x -- , y --;

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
        }
    }

    memset(visited , 0 , sizeof(visited));
    bfs(x , y , 0 , 0);

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            if(visited[i][j]) {
                ans ++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}

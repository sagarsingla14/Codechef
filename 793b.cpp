#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

ll n , m;
char arr[1001][1001];
ll visited[1001][1001][4][5];
ll dx[4] = {0 , 1 , 0 , -1};
ll dy[4] = {1 , 0 , -1 , 0};

ll solve(ll x , ll y , ll t , ll d) {
    if(x < 0 || x >= n || y < 0 || y >= m || t > 2 || arr[x][y] == '*' || visited[x][y][t][d]) {
        return 0;
    }

    if(arr[x][y] == 'T') {
        return 1;
    }
    visited[x][y][t][d] = 1;

    ll ans = 0;
    for(ll i = 0 ; i < 4 ; i++) {
        ans |= solve(x + dx[i] , y + dy[i] , t + ((i == d || d == -1) ? 0 : 1) , i);
    }
    return ans;
}

int main() {
    ll x , y;
    cin >> n >> m;
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 'S') {
                x = i;
                y = j;
            }
        }
    }

    cout << "vis val " << visited[x][y][0][-1] << endl;

    if(solve(x , y , 0 , -1)) {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}

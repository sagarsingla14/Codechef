#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int dx[4] = {0 , 0 , -1 , 1};
int dy[4] = {-1 , 1 , 0 , 0};

ll n , m;
void dfs(int x , int y , vector <vector <int>> &visited , vector <vector <char>> &grid) {
    if(x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != '1' || visited[x][y]) {
        cout << x << " " << y << endl;
        return ;
    }

    visited[x][y] = 1;
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j ++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0 ; i < 4 ; i++) {
        dfs(x + dx[i] , y + dy[i] , visited , grid);
    }
    return ;
}

int numIslands(vector<vector<char>>& grid) {
    vector <vector<int>> visited(grid.size() , vector <int> (grid[0].size() , 0));
    int ans = 0;

    for(int i = 0 ; i < grid.size() ; i++) {
        for(int j = 0 ; j < grid[0].size() ; j++) {
            if(!visited[i][j] && grid[i][j] == '1') {
                ans ++;
                dfs(i , j , visited , grid);
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    vector <vector <char>> grid(n);

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j ++) {
            ll x;
            cin >> x;
            grid[i].push_back(x);
        }
    }
    cout << numIslands(grid) << endl;

    return 0;
}


// 4 5
// 1 1 0 0 0
// 1 1 0 0 0
// 0 0 1 0 0
// 0 0 0 1 1

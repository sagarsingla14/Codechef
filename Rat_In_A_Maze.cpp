#include <bits/stdc++.h>
using namespace std;

int n , ok = 0;
int maze[5][5];
int visited[5][5];

bool isValid(int x , int y) {
    if(x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]) {
        return true;
    }
    return false;
}

void solve(int x , int y , vector <char> &str) {
    if(x == n - 1 && y == n - 1) {
        ok = 1;
        for(auto i : str) {
            cout << i;
        }
        cout << endl;
        return;
    }

    visited[x][y] = 1;
    if(isValid(x , y + 1)) {
        str.push_back('R');
        solve(x , y + 1 , str);
        str.pop_back();
    }
    if(isValid(x , y - 1)) {
        str.push_back('L');
        solve(x , y - 1 , str);
        str.pop_back();
    }
    if(isValid(x + 1 , y)) {
        str.push_back('D');
        solve(x + 1 , y , str);
        str.pop_back();
    }
    if(isValid(x - 1 , y)) {
        str.push_back('U');
        solve(x - 1 , y , str);
        str.pop_back();
    }
    visited[x][y] = 0;
}

int main() {
    cin >> n;
    for(int  i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> maze[i][j];
        }
    }

    memset(visited , 0 , sizeof(visited));

    if(maze[0][0] == 0) {
        cout << -1 << endl;
        return 0;
    }

    visited[0][0] = 1;
    vector <char> str;
    solve(0 , 0 , str);

    if(!ok) {
        cout << -1 << endl;
    }

    return 0;
}

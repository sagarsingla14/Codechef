#include <bits/stdc++.h>
using namespace std;

int board[11][11];
int n , ok = 0;
vector <vector <int>> ans;

bool cmp (vector <int> a , vector <int> b) {
    return a[0] > b[0];
}

void print() {
    vector <int> v;
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(board[i][j]) {
                v.push_back(j);
            }
        }
    }
    ans.push_back(v);
}

bool canPlace(int row , int col) {
    for(int i = 0 ; i < n ; i++) {
        if(board[row][i]) {
            return false;
        }
        if(board[i][col]) {
            return false;
        }
    }

    for(int i = row , j = col ; i >= 0 && j >= 0 ; i --  , j --) {
        if(board[i][j]) {
            return false;
        }
    }

    for(int i = row ,  j = col ; i < n && j >= 0 ; i ++ , j --) {
        if(board[i][j]) {
            return false;
        }
    }
    return true;
}

void solve(int col) {
    if(col == n) {
        print();
        ok = 1;
        return;
    }

    for(int row = 0 ; row < n ; row++) {
        if(canPlace(row , col)) {
            board[row][col] = 1;
            solve(col + 1);
            board[row][col] = 0;
        }
    }
    return;
}

void place() {
    memset(board , 0 , sizeof(board));
    ans.clear();
    ok = 0;
    solve(0);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        place();

        if(!ok) {
            cout << "-1" << endl;
        }
        sort(ans.begin() , ans.end() , cmp);

        for(auto i : ans) {
            cout << '[';
            for(auto j : i) {
                cout << j + 1 << " ";
            }
            cout << "] ";
        }
        cout << endl;
    }
    return 0;
}

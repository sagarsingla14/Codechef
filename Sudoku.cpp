#include <bits/stdc++.h>
using namespace std;

int t , n = 9 , ok;
int sudoku[9][9];
int row[9][10];
int col[9][10];

void print() {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPut(int x , int y , int num) {
    int dx = (x / 3) * 3;
    int dy = (y / 3) * 3;

    for(int i = dx ; i < dx + 3 ; i++) {
        for(int j = dy ; j < dy + 3 ; j++) {
            if(sudoku[i][j] == num) {
                return false;
            }
        }
    }

    if(row[x][num]) {
        return false;
    }

    if(col[y][num]) {
        return false;
    }

    return true;
}

bool canfind(int &i , int &j) {
    for(int x = 0 ; x < n ; x++) {
        for(int y = 0 ; y < n ; y++) {
            if(sudoku[x][y] == 0) {
                i = x;
                j = y;
                return true;
            }
        }
    }
    return false;
}

void solve() {

    int i , j;
    if(!canfind(i , j)) {
        ok = 1;
        print();
        return;
    }

    for(int num = 1 ; num <= 9 ; num ++) {
        if(canPut(i , j , num)) {
            sudoku[i][j] = num;
            row[i][sudoku[i][j]] = 1;
            col[j][sudoku[i][j]] = 1;

            solve();
            if(ok) {
                return;
            }

            row[i][sudoku[i][j]] = 0;
            col[j][sudoku[i][j]] = 0;
            sudoku[i][j] = 0;
        }
    }
    return;
}

int main() {
    cin >> t;
    while(t--) {
        ok = 0;

        memset(sudoku , 0 , sizeof(sudoku));
        memset(row , 0 , sizeof(row));
        memset(col , 0 , sizeof(col));

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                cin >> sudoku[i][j];
                if(sudoku[i][j]) {
                    row[i][sudoku[i][j]] = 1;
                    col[j][sudoku[i][j]] = 1;
                }
            }
        }

        solve();
    }
    return 0;
}

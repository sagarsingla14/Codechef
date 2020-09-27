#include <bits/stdc++.h>
using namespace std;

int n , m , x , y , c , ok , t;
vector <int> graph[51];
int color[51] = {0};

void ClearGlobal() {
    memset(color , 0 , sizeof(color));
    for(int i = 0 ; i <= 50 ; i++) {
        graph[i].clear();
    }
    ok = 0;
}

bool isSafe(int cur , int curColor) {
    for(auto i : graph[cur]) {
        if(color[i] == curColor) {
            return false;
        }
    }
    return true;
}

int solve(int cur) {
    if(cur == n + 1) {
        return 1;
    }

    for(int i = 1 ; i <= c;  i++) {
        if(isSafe(cur , i)) {
            color[cur] = i;
            if(solve(cur + 1)) {
                return true;
            }
            color[cur] = 0;
        }
    }
    return 0;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> c >> m ;
        memset(color , 0 , sizeof(color));

        for(int i = 0 ; i < m ; i++) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        ok = solve(1);
        if(ok) {
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        ClearGlobal();
    }
    return 0;
}

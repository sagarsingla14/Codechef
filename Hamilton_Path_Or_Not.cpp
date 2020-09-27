#include <bits/stdc++.h>
using namespace std;

int t , n , m;
int graph[12][12];
int visited[12];
int ans;

void print(vector <int> &path) {
    cout << "Hamiltonian Path = ";
    for(auto i : path) {
        cout << i << " ";
    }
    cout << endl;
}

bool solve(int cur , int cnt , vector <int> &path) {
    if(cnt == n) {
        print(path);
        return true;
    }

    for(int i = 1 ; i <= n ; i++) {
        if(!visited[i] && graph[cur][i]) {
            visited[i] = 1;
            path.push_back(i);
            if(solve(i , cnt + 1 , path)) {
                return true;
            }
            path.pop_back();
            visited[i] = 0;
        }
    }

    return false;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;

        memset(graph , 0 , sizeof(graph));
        memset(visited , 0 , sizeof(visited));

        for(int i = 0 ; i < m ; i ++) {
            int x , y;
            cin >> x >> y;
            graph[x][y] = 1;
            graph[y][x] = 1;
        }

        bool ok = false;
        vector <int> path;

        for(int i = 1 ; i <= n ; i++) {
            visited[i] = 1;
            path.push_back(i);
            ok = solve(i , 1 , path);
            visited[i] = 0;
            path.pop_back();

            if(ok) {
                break;
            }
        }

        if(ok) {
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl << "No Hamiltonian Path exist" << endl;
        }
    }
	return 0;
}

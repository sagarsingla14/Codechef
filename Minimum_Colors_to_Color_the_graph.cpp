#include <bits/stdc++.h>
using namespace std;

int n , m , x , y;
vector <int> graph[100001];
int degree[100001] = {0};
vector <pair <int , int>> v;
int ans = 0 , color = 0;
int visited[100001] = {0};

void solve(int start , int index) {
    visited[start] = color;
    for(int i = index ; i < n ; i++) {
        if(visited[v[i].second] == -1) {
            int ok = 1;
            for(auto itr : graph[v[i].second]) {
                if(visited[itr] == color) {
                    ok = 0;
                    break;
                }
            }
            if(ok) {
                visited[v[i].second] = color;
            }
        }
    }
}

int main() {
    cin >> n >> m ;
    memset(visited , -1 , sizeof(visited));

    for(int i = 0 ; i < m ; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        degree[x] ++;
        degree[y] ++;
    }

    for(int i = 1 ; i <= n ; i++) {
        v.push_back({-degree[i] , i});
    }

    sort(v.begin() , v.end());
    ans = 0;

    for(int i = 0 ; i < n ; i++) {
        if(visited[v[i].second] == -1) {
            color ++;
            solve(v[i].second , i);
        }
    }

    cout << "d ";
    for(int i = 1 ; i <= n ; i++) {
        cout << degree[i] << " ";
    }
    cout << endl;

    cout << "s ";
    for(auto i : v) {
        cout << i.second << " " << -i.first << endl;
    }
    cout << endl;

    cout << "c ";
    for(int i = 1 ; i <= n ; i++) {
        cout << visited[i] << " ";
    }
    cout << endl;

    cout << color << endl;
    return 0;
}

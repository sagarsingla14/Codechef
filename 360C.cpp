#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> graph[100001];
ll color[100001];
ll degree[100001];
ll n , m , u , v;
set <ll> a;
set <ll> b;
ll ok = 1;


void bfs(ll start) {
    queue <ll> q;
    color[start] = 1;
    q.emplace(start);

    while(!q.empty()) {
        ll curVertex = q.front();
        ll curColor = color[curVertex];
        q.pop();

        if(curColor == 1) {
            a.insert(curVertex);
        }
        if(curColor == 2) {
            b.insert(curVertex);
        }

        for(auto i : graph[curVertex]) {
            if(color[i] == 0) {
                if(curColor == 1) {
                    color[i] = 2;
                }
                else if(curColor == 2){
                    color[i] = 1;
                }
                q.emplace(i);
            }
            else{
                if(color[i] == curColor) {
                    ok = 0;
                }
            }
        }
    }
}

void printAnswer() {
    if(ok) {
        cout << a.size() << endl;
        for(auto i : a) {
            cout << i << " ";
        }
        cout << endl;

        cout << b.size() << endl;
        for(auto i : b) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    ok = 1;
    memset(color , 0 , sizeof(color));
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u] ++;
        degree[v] ++;
    }

    for(ll i = 1 ; i <= n ; i++) {
        if(!color[i] && degree[i] != 0) {
            bfs(i);
        }
    }

    printAnswer();
}

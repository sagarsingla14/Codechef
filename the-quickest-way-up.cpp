#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n , t , m;
vector <ll> graph[100001];
ll visited[100001];
map <ll , ll> ladder;
map <ll , ll> snake;
ll moves[1001];


void bfs(ll start) {
    moves[start] = 1;
    visited[start] = 1;
    queue <ll> q;
    q.emplace(start);
    while(!q.empty()) {
        ll parent = q.front();
        q.pop();
        for(auto i : graph[parent]) {
            if(!visited[i]) {
                q.push(i);
                moves[i] = moves[parent] + 1;
                visited[i] = 1;
            }
            else{
                moves[i] = min(moves[i] , moves[parent] + 1);
            }
        }
    }
}

void formGraph() {
    for(ll i = 1 ; i < 100 ; i++) {
        if(!snake[i] && !ladder[i]) {
            for(ll j = 1 ; j <= 6 ; j++) {
                if(snake[i + j]) {
                    graph[i].push_back(snake[i + j]);
                }
                else if(ladder[i + j]) {
                    graph[i].push_back(ladder[i + j]);
                }
                else{
                    graph[i].push_back(i + j);
                }
            }
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 0 ; i < n ; i++) {
            ll u , v;
            cin >> u >> v;
            ladder[u] = v;
        }

        cin >> m;
        for(ll i = 0 ; i < m ; i++) {
            ll u , v;
            cin >> u >> v;
            snake[u] = v;
        }

        formGraph();

        memset(visited , 0 , sizeof(visited));
        memset(moves , 0 , sizeof(moves));
        bfs(1);

        ll possible = 0;
        for(ll i = 100 ; i <= 105 ; i++) {
            if(moves[i]) {
                possible = 1;
                break;
            }
        }
        if(possible) {
            cout << moves[100] - 1 << endl;
        }
        else{
            cout << -1 << endl;
        }

        for(ll i = 1 ; i <= 110 ; i++) {
            graph[i].clear();
        }
        snake.clear();
        ladder.clear();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n , m , u , v;
vector <ll> graph[100001];
ll visited[100001];
vector <ll> ans;
priority_queue <ll , vector <ll> , greater <ll> > pq;

void input() {
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void bfs(ll start) {
    pq.emplace(start);
    visited[start] = 1;
    while(!pq.empty()) {
        ll node = pq.top();
        ans.push_back(node);
        pq.pop();
        for(auto i : graph[node]) {
            if(!visited[i]) {
                pq.emplace(i);
                visited[i] = 1;
            }
        }
    }
}

void solve() {
    memset(visited , 0 , sizeof(visited));
    bfs(1);
}

void printAnswer() {
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    input();
    solve();
    printAnswer();
}

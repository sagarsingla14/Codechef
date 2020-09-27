#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

stack <ll> s;
vector <vector <ll> > component;
vector <ll> graph[100001];
vector <ll> rgraph[100001];
ll visited[100001];

void dfs(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    s.push(start);
}

// KosaRajus Algorithm for finding strongly connected components..
vector <ll> curCompon;
void KosaRajus(ll start) {
    visited[start] = 1;
    for(auto i : rgraph[start]) {
        if(!visited[i]) {
            KosaRajus(i);
        }
    }
    curCompon.push_back(start);
}

void findComponent() {
    memset(visited , 0 , sizeof(visited));
    while (!s.empty()) {
        ll start = s.top();
        if(!visited[start]) {
            KosaRajus(start);
            component.push_back(curCompon);
            curCompon.clear();
            s.pop();
        }
        else{
            s.pop();
        }
    }
}

int main() {
    ll n;
    cin >> n;
    ll arr[n + 1] = {0};
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }
    ll m;
    cin >> m;
    while(m--) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    memset(visited , 0 , sizeof(visited));
    ll comp = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    findComponent();

    cout << component.size() << endl;

    return 0;
}

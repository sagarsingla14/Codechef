#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m , d , degree = 0;
vector <ll> graph[200001];
ll visited[200001] = {0};
vector <pair <ll , ll>> v;
map <ll , ll> mp;

void dfs(ll start , vector <ll> &component) {
    visited[start] = 1;
    component.push_back(start);
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i , component);
        }
    }
}

void bfs(ll start) {
    visited[start] = 1;
    queue <ll> q;
    q.push(start);
    while(!q.empty()) {
        ll val = q.front();
        q.pop();
        for(auto i : graph[val]) {
            if(!visited[i]) {
                visited[i] = 1;
                v.push_back({val , i});
                q.push(i);
            }
        }
    }
}

int main() {
    cin >> n >> m >> d;
    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        if(u == 1 || v == 1) {
            degree ++;
            if(u == 1) {
                mp[v] ++;
            }
            else if(v == 1){
                mp[u] ++;
            }
        }
        else{
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    vector <vector <ll>> components;
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            vector <ll> component;
            dfs(i , component);
            components.push_back(component);
        }
    }

    if(degree < d || components.size() - 1> d) {
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        ll cnt = 0;
        for(auto i : components) {
            for(auto j : i) {
                if(mp[j]) {
                    cnt ++;
                    mp[j] = 0;
                    graph[1].push_back(j);
                    graph[j].push_back(1);
                    break;
                }
            }
        }
        for(auto i : mp) {
            if(i.second && cnt < d) {
                graph[1].push_back(i.first);
                graph[i.first].push_back(1);
                cnt ++;
            }
        }

        memset(visited , 0 , sizeof(visited));
        bfs(1);

        for(auto i : v) {
            cout << i.first << " " << i.second << endl;
        }
    }
    return 0;
}

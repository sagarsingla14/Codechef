#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll t;
string ans;
ll ok = 0;
ll dfsnum[26] = {0};
ll visited[26] = {0};
ll need[26] = {0};
ll present[26] = {0};
ll parent[26] = {0};
stack <ll> ss;

ll timee = 0;
vector <ll> graph[26];

void cycle(ll root) {
    visited[root] = 1;
    for(auto i : graph[root]) {
        if(visited[i] == 0) {
            cycle(i);
        }
        else if(visited[i] == 1) {
            ok = 0;
        }
    }
    visited[root] = 2;
}

void dfs(ll u) {
    visited[u] = 1;
    for(ll i = 0 ; i < graph[u].size() ; i++) {
        if(!visited[graph[u][i]]) {
            dfs(graph[u][i]);
        }
    }
    ss.push(u);
}

void topo() {
    for(ll i = 0 ; i < 26 ; i++) {
        if(!visited[i] && present[i]) {
            dfs(i);
        }
    }
}

void printSolution() {
    while(!ss.empty()) {
        ans += ('A' + ss.top());
        ss.pop();
    }
    reverse(ans.begin() , ans.end());
}

int main() {

    cin >> t;
    ll tc = 0;
    while(t--) {
        memset(need , 0 , sizeof(need));
        memset(present , 0 , sizeof(present));
        ans = "";
        tc ++;
        ll n , m;
        cin >> n >> m;
        ll arr[n][m];
        for(ll i = 0 ; i < n ; i++) {
            string str;
            cin >> str;
            for(ll j = 0 ; j < m ; j ++) {
                arr[i][j] = str[j];
            }
        }

        map <pair <ll , ll>  , ll> edges;


        for(ll i = 0 ; i < n ; i ++) {
            for(ll j = 0 ; j < m ; j ++) {
                present[arr[i][j] - 'A'] ++;
                if(i != n - 1) {
                    if(arr[i][j] != arr[i + 1][j]) {
                        edges[{arr[i][j] - 'A' , arr[i + 1][j] - 'A'}] = 1;
                        need[arr[i][j] - 'A'] = 1;
                        need[arr[i + 1][j] - 'A'] = 1;
                    }
                }
            }
        }


        map <pair <ll , ll>  , ll> :: iterator itr;
        for(itr = edges.begin() ; itr != edges.end() ; itr++) {
            ll u = (itr -> first).first;
            ll v = (itr -> first).second;
            graph[u].push_back(v);
        }

        memset(visited , 0 , sizeof(visited));
        memset(dfsnum , 0 , sizeof(dfsnum));
        memset(parent , 0 , sizeof(parent));

        ok = 1;
        for(ll i = 0 ; i < 26 ; i++) {
            if(visited[i] == 0 && present[i]) {
                cycle(i);
            }
        }

        if(!ok) {
            cout << "Case #" << tc << ": " << -1 << endl;
        }
        else{
            memset(visited , 0 , sizeof(visited));
            topo();
            printSolution();
            cout << "Case #" << tc << ": " << ans << endl;
        }

        for(ll i = 0 ; i < 26 ; i ++) {
            graph[i].clear();
        }
    }
    return 0;
}

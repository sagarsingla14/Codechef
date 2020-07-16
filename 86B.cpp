#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> graph[500001];
ll visited[500001];
map <string , ll> hsah;
map <ll , string> antihsah;
ll n , m;
vector <ll> ans;

void dfs(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    memset(visited , 0 , sizeof(visited));
    cin >> n >> m;

    for(ll i = 1 ; i <= n ; i++) {
        string str;
        cin >> str;
        hsah[str] = i;
        antihsah[i] = str;
    }

    for(ll i = 0 ; i < m ; i++) {
        string s1 , s2;
        cin >> s1 >> s2;
        ll u = hsah[s1];
        ll v = hsah[s2];

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            ans.push_back(i);
            dfs(i);
        }
    }

    map <string , ll> lexo;
    cout << ans.size() << endl;
    for(auto i : ans) {
        lexo[antihsah[i]] = 1;
    }

    for(auto i : lexo) {
        cout << i.first << endl;
    }

    return 0;
}

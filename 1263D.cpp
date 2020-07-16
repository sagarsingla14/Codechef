#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> graph[26];
unordered_map <ll , ll> present;
bool visited[26];

void dfs(ll start) {
    visited[start] = true;
    for(auto i = 0; i < graph[start].size(); i++) {
        if(!visited[graph[start][i]]) {
            dfs(graph[start][i]);
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        ll l = str.length();

        if(str.length() > 1) {
            for(ll i = 1 ; i < str.length() ; i++) {
                graph[str[i - 1] - 97].push_back(str[i] - 97);
            }
        }

        for(ll i = 0; i < l ; i++) {
            present[str[i] - 97] = 1;
        }
    }

    ll ans = 0;

    for(ll i = 0 ; i < 26 ; i++ ) {
        if(!visited[i] && present[i]) {
            dfs(i);
            ans ++;
        }
    }

    cout << ans << endl;
    return 0;
}

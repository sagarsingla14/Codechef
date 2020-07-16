#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll> graph[200001];
ll visited[200001];
ll color[200001];
map <ll , ll> c;
ll k, n, q, ok, u, v , root1 = 0 , root2 = 0;

set <ll> s;
void dfs2(ll start) {
    visited[start] = 1;
    s.insert(color[start]);
    for(auto i : graph[start]) {
        if(start == root2) {
            if(s.size() > 1) {
                ok = 0;
            }
            s.clear();
        }
        if(!visited[i]) {
            dfs2(i);
        }
    }
    if(start == root2) {
        if(s.size() > 1) {
            ok = 0;
        }
        s.clear();
    }
}

void dfs1(ll start) {
    visited[start] = 1;
    s.insert(color[start]);
    for(auto i : graph[start]) {
        if(start == root1) {
            if(s.size() > 1) {
                ok = 0;
            }
            s.clear();
        }
        if(!visited[i]) {
            dfs1(i);
        }
    }
    if(start == root1) {
        if(s.size() > 1) {
            ok = 0;
        }
        s.clear();
    }
}

void findRoots() {
    if(c.size() == 1) {
        cout << "YES" << endl << 1 << endl;
        ok = 2;
        return;
    }


    for(auto i : c) {
        if(root1 == 0) {
            root1 = i.second;
        }
        else if(root2 == 0){
            root2 = i.second;
        }
        else{
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(visited , 0 , sizeof(visited));
    memset(color , 0 , sizeof(color));

    cin >> n;
    for(ll i = 0 ; i < n - 1 ; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(ll i = 1 ; i <= n ; i++) {
        cin >> color[i];
        if(!c[color[i]]) {
            c[color[i]] = i;
        }
    }

    findRoots();
    if(ok == 2) {
        return 0;
    }

    ok = 1;
    memset(visited , 0 , sizeof(visited));
    dfs1(root1);
    if(ok) {
        cout << "YES" << endl << root1 << endl;
    }
    else{
        ok = 1;
        s.clear();
        memset(visited , 0 , sizeof(visited));
        dfs2(root2);

        if(ok) {
            cout << "YES" << endl << root2 << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

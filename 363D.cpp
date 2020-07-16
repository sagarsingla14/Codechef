#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 1e18

ll n , ans , root;
ll visited[300001];
ll level[300001];
ll degree[300001];
ll sum[300001];
ll arr[300001];
map <ll , ll> mp;
vector <ll> graph[300001];
map <ll , ll> freq;

void dfs(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

void findRoot() {
    root = 0;
    for(ll i = 1 ; i <= n ; i++) {
        if(freq[i] > freq[root] && mp[i] != 0) {
            root = i;
        }
    }
}

void fixSelfRoot() {
    for(ll i = 1 ; i <= n ; i++) {
        if(i == arr[i] && arr[i] != root) {
            arr[i] = root;
            ans ++;
        }
    }
}

void formGraph() {
    for(ll i = 1 ; i <= n ; i++) {
        graph[arr[i]].push_back(i);
        graph[i].push_back(arr[i]);
    }
}

void ifRootNotFound(){
    if(root == 0) {
        for(ll i = 1 ; i <= n ; i++) {
            if(freq[i] > freq[root]) {
                root = i;
            }
        }
        ans ++;
        arr[root] = root;
    }
}

void printAns() {
    cout << ans << endl;
    for(ll i = 1 ; i <= n ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve() {
    set <ll> s;
    for(ll i = 1 ; i <= n ; i++) {
        if(!visited[i]) {
            dfs(i);
            s.insert(i);
            ans ++;
        }
    }
    for(auto i : s) {
        arr[i] = root;
    }
}

void inp() {
    cin >> n;
    ans = 0;
    memset(visited , 0 , sizeof(visited));
    memset(level , 0 , sizeof(level));

    freq[0] = 0;
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
        freq[arr[i]] ++;

        if(arr[i] == i) {
            mp[arr[i]] = 1;
        }
    }
}

int main() {
    inp();
    findRoot();
    ifRootNotFound();
    fixSelfRoot();
    formGraph();
    dfs(root);
    solve();
    printAns();
}

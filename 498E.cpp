#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector <ll> graph[200001];
ll visited[200001];
ll arr[200001];
ll child[200001];
vector <ll> answerSegment;
ll u, k, n, q, ok;
unordered_map <ll , ll> indx;

void dfs(ll start) {
    answerSegment.push_back(start);
    visited[start] = 1;
    ll countChild = 0;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
            countChild += child[i];
        }
    }
    countChild ++;
    child[start] = countChild;
}

void setMap() {
    for(ll i = 0 ; i < n ; i++) {
        indx[answerSegment[i]] = i;
    }
}

void checkOk() {
    if(child[u] < k) {
        ok = 0;
    }
}

void calcAnswer() {
    ll pos = indx[u];
    pos += k;
    pos --;
    cout << answerSegment[pos] << endl;
}

int main() {
    memset(visited , 0 , sizeof(visited));
    memset(arr , 0 , sizeof(arr));
    memset(child , 0 , sizeof(child));

    cin >> n >> q;
    for(ll i = 2 ; i <= n ; i++) {
        cin >> arr[i];
    }

    for(ll i = 2 ; i <= n ; i++) {
        graph[arr[i]].push_back(i);
        graph[i].push_back(arr[i]);
    }

    memset(visited , 0 , sizeof(visited));
    dfs(1);

    memset(visited , 0 , sizeof(visited));
    setMap();

    while(q--) {
        ok = 1;
        cin >> u >> k;
        checkOk();
        if(ok) {
            calcAnswer();
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;


ll n , m;
ll visited[500001];
ll level[500001];
ll degree[500001];
vector <ll> graph[500001];
vector <pair <ll , ll> > v(500001);
vector <ll> ans;

ll dp[500001][2];

void setLevel(ll start , ll curlevel) {
    visited[start] = 1;
    level[start] = curlevel;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            setLevel(i , curlevel + 1);
        }
    }
}

void dfs(ll start , ll parent , ll nextodd , ll nexteven) {
    visited[start] = 1;

    dp[start][0] += nexteven;
    dp[start][1] += nextodd;
    dp[start][0] %= 2;
    dp[start][1] %= 2;

    ll l = level[start] % 2;
    if(dp[parent][l]) {
        v[start].first ^= 1;
    }

    if(v[start].first != v[start].second) {
        ans.push_back(start);
        if(l == 1) {
            nextodd ++;
        }
        else{
            nexteven ++;
        }
        nextodd %= 2;
        nexteven %= 2;
    }
    // cout << "s , p , no , ne level " << start << " " << parent << " " << nextodd << " " << nexteven << " "  << level[start] << endl;

    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i , start , nextodd , nexteven);
        }
    }
}



int main() {
    memset(visited , 0 , sizeof(visited));
    memset(degree , 0 , sizeof(degree));
    memset(level , 0 , sizeof(level));
    memset(dp , 0 , sizeof(dp));


    ll n;
    cin >> n;
    for(ll i = 0 ; i < n - 1 ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    setLevel(1 , 1);
    vector <ll> goal(n) , init(n);
    for(ll i = 0 ; i < n ; i++) {
        cin >> init[i];
    }
    for(ll i = 0 ; i < n ; i++) {
        cin >> goal[i];
    }
    for(ll i = 0 ; i < n ; i++) {
        v[i + 1] = make_pair(init[i] , goal[i]);
    }

    ll flips = 0;
    memset(visited , 0 , sizeof(visited));
    dfs(1 , 0 , 0 , 0);

    cout << ans.size() << endl;
    for(ll i = 0 ; i < ans.size() ; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}

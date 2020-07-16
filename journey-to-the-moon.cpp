#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector <ll> graph[100000];
vector <ll> ans;
ll visited[100000];
ll s , n , m , result , one;

vector <ll> component;
void dfs(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    component.push_back(start);
}

void printAns(ll sum) {
    result = (one * (one - 1)) / 2;
    result += (one * sum);
    for(ll i = 0 ; i < ans.size() ; i++) {
        for(ll j = i + 1 ; j < ans.size() ; j++) {
            if(ans[j] == 1 && ans[i] == 1) {
                continue;
            }
            else{
                result += (ans[i] * ans[j]);
            }
        }
    }

    cout << result << endl;
    ans.clear();
}

int main() {
    cin >> n >> m;

    for(ll i = 0 ; i < m ; i++) {
        ll u , v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(visited , 0 , sizeof(visited));
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(!visited[i]) {
            dfs(i);
            if(component.size() == 1) {
                one ++;
            }
            else{
                sum += component.size();
                ans.push_back(component.size());
            }

            component.clear();
        }
    }

    printAns(sum);

    return 0;
}

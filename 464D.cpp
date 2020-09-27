#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <char> graph[26];
ll visited[26] = {0};

void dfs(ll start , vector <ll> &component) {
    visited[start] = 1;
    component.push_back(start);
    for(auto i : graph[start]) {
        if(!visited[i - 'a']) {
            dfs(i - 'a' , component);
        }
    }
}

int main() {
    ll n;
    cin >> n;
    string a , b;
    cin >> a >> b;

    ll ans = 0;
    memset(visited , 0 , sizeof(visited));

    for(ll i = 0 ; i < n ; i++) {
        if(a[i] != b[i]) {
            graph[a[i] - 'a'].push_back(b[i]);
            graph[b[i] - 'a'].push_back(a[i]);
        }
    }

    vector <vector <ll> > components;
    for(ll i = 0 ; i < 26 ; i++) {
        if(!visited[i]) {
            vector <ll> component;
            dfs(i , component);
            ans += (component.size() - 1);
            if(component.size() > 1) {
                components.push_back(component);
            }
        }
    }

    cout << ans << endl;
    for(auto i : components) {
        for(ll j = 1 ; j < i.size() ; j++) {
            cout << char('a' + i[j - 1]) << " " << char('a' + i[j]) << endl;
        }
    }

    return 0;
}

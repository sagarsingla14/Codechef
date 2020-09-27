#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

vector <char> graph[26];
ll t;
ll n;
string a , b;
ll ans = 0;
ll visited[26] = {0};
ll ok = 1;

void dfs(ll s , vector <ll> &component) {
    visited[s] = 1;
    component.push_back(s);
    for(auto i : graph[s]) {
        if(!visited[i - 'a']) {
            dfs(i - 'a' , component);
        }
    }
}

int main() {
    cin >> t;
    for(ll i = 0 ; i < t ; i++) {
        cin >> n;
        cin >> a >> b;
        ans = 0 , ok = 1;
        for(ll i = 0 ; i < n ; i++) {
            if(b[i] < a[i]) {
                ok = 0;
                break;
            }
        }

        ll present[26] = {0};
        for(ll i = 0 ; i < n ; i++) {
            present[a[i] - 'a'] ++;
        }

        for(char i = 'a' ; i < 'z' ; i++) {
            if(present[i - 'a']) {
                for(ll j = 0 ; j < n ; j++) {
                    if(a[j] == i && a[j] != b[j])  {
                        graph[b[j] - 'a'].push_back(i);
                        graph[i - 'a'].push_back(b[j]);
                    }
                }
            }
        }

        for(char i = 'a' ; i < 'z' ; i++) {
            if(!visited[i - 'a']) {
                vector <ll> component;
                dfs(i - 'a' , component);
                ans += component.size() - 1;
            }
        }
        cout << ans << endl;

        for(ll i = 0 ; i < 26 ; i++) {
            graph[i].clear();
        }
        memset(visited , 0 , sizeof(visited));
    }
    return 0;
}

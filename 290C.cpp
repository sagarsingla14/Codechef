#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

ll n;
vector <ll> graph[26];
ll visited[26] = {0};
vector <ll> v;
ll ans = 1;

void dfs(ll start) {
    visited[start] = 1;
    for(auto i : graph[start]) {
        if(!visited[i]) {
            dfs(i);
        }
        else if(visited[i] == 1) {
            ans = 0;
        }
    }
    visited[start] = 2;
    v.push_back(start);
}

int main() {
    fast_io
    cin >> n;
    string str[n];
    for(ll i = 0 ; i < n ; i++) {
        cin >> str[i];
    }

    ans = 1;
    for(ll i = 0 ; i < n - 1 ; i ++) {
        ll ok = 0;
        for(ll j = 0 ; j < min(str[i + 1].size() , str[i].size()) ; j ++) {
            if(str[i][j] != str[i + 1][j]) {
                graph[str[i][j] - 'a'].push_back(str[i + 1][j] - 'a');
                ok = 1;
                break;
            }
        }

        if(!ok && str[i].size() > str[i + 1].size()) {
            ans = 0;
            break;
        }
    }

    if(!ans) {
        cout << "Impossible" << endl;
    }
    else{
        memset(visited , 0 , sizeof(visited));
        for(ll i = 0 ; i < 26 ; i ++) {
            if(!visited[i]) {
                dfs(i);
            }
        }
        if(!ans) {
            cout << "Impossible" << endl;
        }
        else{
            reverse(v.begin() , v.end());
            for(auto i : v) {
                cout << char('a' + i);
            }
            cout << endl;
        }
    }
    return 0;
}



// 7
// car
// care
// careful
// carefully
// becarefuldontforgetsomething
// otherwiseyouwillbehacked
// goodluck

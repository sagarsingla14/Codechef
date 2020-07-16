#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , m;

bool isValid(pair <ll , ll> i) {
    return i.first >= 1 && i.first <= n && i.second >= 1 && i.second <= m;
}

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        char arr[n + 2][m + 2];
        ll dp[n + 2][m + 2];
        memset(dp , 0 , sizeof(dp));

        for(ll i = 0 ; i <= n + 1 ; i++) {
            for(ll j = 0 ; j <= m + 1 ; j++) {
                arr[i][j] = '-';
            }
        }

        for(ll i = 1 ; i <= n ; i++) {
            string str;
            cin >> str;
            for(ll j = 1 ; j <= m ; j++) {
                arr[i][j] = str[j - 1];
            }
        }

        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= m ; j++) {
                if(arr[i][j] == 'B') {
                    if(arr[i + 1][j] == '.' || arr[i + 1][j] == '-') {
                        arr[i + 1][j] = '#';
                    }
                    if(arr[i][j + 1] == '.' || arr[i][j + 1] == '-') {
                        arr[i][j + 1] = '#';
                    }
                    if(arr[i - 1][j] == '.' || arr[i - 1][j] == '-') {
                        arr[i - 1][j] = '#';
                    }
                    if(arr[i][j - 1] == '.' || arr[i][j - 1] == '-') {
                        arr[i][j - 1] = '#';
                    }
                }
            }
        }

        ll visited[n + 2][m + 2];
        memset(visited , 0 , sizeof(visited));

        queue <pair <ll , ll> > q;
        if(arr[n][m] == '.') {
            visited[n][m] = 1;
            q.push({n , m});
        }

        while(!q.empty()) {
            pair <ll , ll> cur = q.front();
            q.pop();
            pair <ll , ll> up , down , right , left;
            up = cur;
            down = cur;
            left = cur;
            right = cur;
            up.first --;
            down.first ++;
            left.second --;
            right.second ++;
            if(isValid(up)) {
                if(!visited[up.first][up.second] && arr[up.first][up.second] != '#') {
                    visited[up.first][up.second] = 1;
                    q.push({up.first , up.second});
                }
            }
            if(isValid(down)) {
                if(!visited[down.first][down.second] && arr[down.first][down.second] != '#') {
                    visited[down.first][down.second] = 1;
                    q.push({down.first , down.second});
                }
            }
            if(isValid(left)) {
                if(!visited[left.first][left.second] && arr[left.first][left.second] != '#') {
                    visited[left.first][left.second] = 1;
                    q.push({left.first , left.second});
                }
            }
            if(isValid(right)) {
                if(!visited[right.first][right.second] && arr[right.first][right.second] != '#') {
                    visited[right.first][right.second] = 1;
                    q.push({right.first , right.second});
                }
            }
        }

        ll ok = 1;
        for(ll i = 1 ; i <= n ; i++) {
            for(ll j = 1 ; j <= m ; j++) {
                if(arr[i][j] == 'G' && visited[i][j] == 0) {
                    ok = 0;
                    break;
                }
                if(arr[i][j] == 'B' && visited[i][j] == 1) {
                    ok = 0;
                    break;
                }
            }
        }

        if(ok) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

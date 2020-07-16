#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io
    ll t;
    cin >> t;
    while(t--) {
        ll n , m , x , y;
        cin >> n >> m >> x >> y;

        string str[n];
        for(ll i = 0 ; i < n ; i++) {
            cin >> str[i];
        }

        ll dot = 0;
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < m ; j++) {
                if(str[i][j] == '.') {
                    dot ++;
                }
            }
        }

        if(2 * x <= y) {
            ll ans = x * dot;
            cout << ans << endl;
        }
        else{
            ll ans = 0;
            for(ll i = 0 ; i < n ; i++) {
                for(ll j = 1 ; j < m ; j++) {
                    if(str[i][j] == '*') {
                        if(str[i][j - 1] == '.') {
                            ans += x;
                            str[i][j - 1] = '*';
                        }
                        else{
                            continue;
                        }
                    }
                    if(str[i][j] == '.') {
                        if(str[i][j - 1] == '.') {
                            ans += y;
                            str[i][j - 1] = '*';
                            str[i][j] = '*';
                        }
                        else {
                            continue;
                        }
                    }
                }
            }

            for(ll i = 0 ; i < n ; i++) {
                if(str[i][m - 1] == '.') {
                    ans += x;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n , m;
    cin >> n >> m;
    ll arr[n][m];
    for(ll i = 0 ; i < n ; i ++) {
        for(ll j = 0 ; j < m ; j ++) {
            cin >> arr[i][j];
        }
    }

    ll pos[n][m];
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            pos[i][j] = -1;
        }
    }

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            if(arr[i][j] == 0) {
                for(ll k = 0 ; k < n ; k ++) {
                    pos[k][j] = 0;
                }
                for(ll k = 0 ; k < m ; k ++) {
                    pos[i][k] = 0;
                }
            }
        }
    }

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j ++) {
            if(pos[i][j] == -1) {
                pos[i][j] = 1;
            }
            // cout << pos[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << endl;


    ll final[n][m];
    memset(final , 0 , sizeof(final));

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            ll orr = 0;
            for(ll k = 0 ; k < n ; k ++) {
                orr |= pos[k][j];
            }
            for(ll k = 0 ; k < m ; k ++) {
                orr |= pos[i][k];
            }

            final[i][j] = orr;
            // cout << final[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << endl;

    ll ok = 1;
    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            if(final[i][j] != arr[i][j]) {
                ok = 0;
                break;
            }
        }
    }

    if(ok) {
        cout << "YES" << endl;
        for(ll i = 0 ; i < n ; i++) {
            for(ll j = 0 ; j < m ; j ++) {
                cout << pos[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}

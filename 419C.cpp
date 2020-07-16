#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n , m;
    cin >> n >> m;

    ll arr[n + 1][m + 1];
    ll brr[n + 1][m + 1];

    memset(arr , 0 , sizeof(arr));
    memset(brr , 0 , sizeof(arr));

    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= m ; j++) {
            cin >> arr[i][j];
            brr[i][j] = arr[i][j];
        }
    }

    vector <ll> row , col , rowb , colb;

    for(ll i = 1 ; i <= m ; i++) {
        if(arr[1][i]) {
            while(arr[1][i]) {
                ll flag = 1;
                for(ll j = 1 ; j <= n ; j++) {
                    if(arr[j][i] == 0) {
                        flag = 0;
                    }
                }
                if(flag) {
                    col.push_back(i);
                    for(ll j = 1 ; j <= n ; j++) {
                        arr[j][i] --;
                    }
                }
                else {
                    break;
                }
            }
        }
    }

    for(ll i = 1 ; i <= n ; i++) {
        if(arr[i][1]) {
            while(arr[i][1]) {
                ll flag = 1;
                for(ll j = 1 ; j <= m ; j++) {
                    if(arr[i][j] == 0) {
                        flag = 0;
                    }
                }
                if(flag) {
                    row.push_back(i);
                    for(ll j = 1 ; j <= m ; j++) {
                        arr[i][j] --;
                    }
                }
                else {
                    break;
                }
            }
        }
    }

    ll impos = 0;
    for(ll i = 1 ; i <= n ; i++) {
        for(ll j = 1 ; j <= m ; j++) {
            if(arr[i][j]) {
                impos = 1;
                break;
            }
        }
        if(impos) {
            break;
        }
    }

    if(impos) {
        cout << -1 << endl;
    }
    else{
        for(ll i = 1 ; i <= n ; i++) {
            if(brr[i][1]) {
                while(brr[i][1]) {
                    ll flag = 1;
                    for(ll j = 1 ; j <= m ; j++) {
                        if(brr[i][j] == 0) {
                            flag = 0;
                        }
                    }
                    if(flag) {
                        rowb.push_back(i);
                        for(ll j = 1 ; j <= m ; j++) {
                            brr[i][j] --;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }

        for(ll i = 1 ; i <= m ; i++) {
            if(brr[1][i]) {
                while(brr[1][i]) {
                    ll flag = 1;
                    for(ll j = 1 ; j <= n ; j++) {
                        if(brr[j][i] == 0) {
                            flag = 0;
                        }
                    }
                    if(flag) {
                        colb.push_back(i);
                        for(ll j = 1 ; j <= n ; j++) {
                            brr[j][i] --;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }

        if(rowb.size() + colb.size() <= col.size() + row.size()) {
            cout << colb.size() + rowb.size() << endl;
            for(auto i : colb) {
                cout << "col " << i << endl;
            }
            for(auto i : rowb) {
                cout << "row " << i << endl;
            }
        }
        else{
            cout << col.size() + row.size() << endl;
            for(auto i : col) {
                cout << "col " << i << endl;
            }
            for(auto i : row) {
                cout << "row " << i << endl;
            }
        }
    }
    return 0;
}

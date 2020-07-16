#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll r , c;
void outputSpecial() {
    ll arr[max(r , c)] = {0};
    arr[0] = 2;
    for(ll i = 1 ; i < max(r , c) ; i++) {
        arr[i] = i + 2;
    }

    if(r == 1) {
        for(ll i = 0 ; i < c ; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else{
        for(ll i = 0 ; i < r ; i++) {
            cout << arr[i] << endl;
        }
    }
}

int main() {
    cin >> r >> c;
    ll dp[r][c];
    memset(dp , 0 , sizeof(dp));

    if(r == 1 && c == 1) {
        cout << 0 << endl;
    }
    else if(r == 1 || c == 1){
        outputSpecial();
    }
    else{

        for(ll i = 1 ; i <= r ; i++) {
            for(ll j = 1 ; j <= c ; j++) {
                dp[i - 1][j - 1] = i * (r + j);
            }
        }

        for(ll i = 0 ; i < r ; i++) {
            for(ll j = 0 ; j < c ; j++) {
                cout << dp[i][j]  << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

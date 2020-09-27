#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll power(ll x , ll y) {
    ll res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1ll;
    }
    return res;
}


void solve(int n , int m , vector <vector <int>> arr) {
    vector <vector <int>> dp(n , vector <int> v(m , 0));
    for(int i = 0 ; i < m ; i++) {
        if(i == 0) {
            dp[0][i] = arr[0][i];
        }
        else{
            dp[0][i] = arr[0][i] ^ dp[0][i - 1];
        }
    }
    for(int i = 0 ; i < n ; i++) {
        if(i == 0) {
            dp[i][0] = arr[i][0];
        }
        else{
            dp[i][0] = arr[i][0] ^ dp[i - 1][0];
        }
    }
    for(int i = 1 ; i < n ; i++) {
        for(int j = 1 ; j < m ; j++) {
            dp[i][j] = (arr[i][j] ^ dp[i - 1][j]) ^ dp[i][j - 1]; 
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        sort(arr , arr + n);
    }
    return 0;
}

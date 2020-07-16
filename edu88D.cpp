#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INF -1000000000
#define k 25
#define MAX 100000


ll arr[100001] = {0};
ll st[MAX][k];
ll stMx[MAX][k];
ll dp[MAX][k];
ll n , q;
ll ans = 0;

void calcSparseTable() {
    for(ll i = 0 ; i < n ; i++) {
        st[i][0] = arr[i];
        stMx[i][0] = arr[i];
        dp[i][0] = 0;
    }
    for(ll j = 1 ; j <= k ; j ++) {
        for(ll i = 0 ; (i + (1ll << j)) <= n ; i++) {
            st[i][j] = st[i][j - 1] + st[i + (1ll << (j - 1))][j - 1];
        }
    }
    for(ll j = 1 ; j <= k ; j ++) {
        for(ll i = 0 ; (i + (1ll << j)) <= n ; i++) {
            stMx[i][j] = max(stMx[i][j - 1] , stMx[i + (1ll << (j - 1))][j - 1]);
        }
    }

    for(ll j = 1 ; j <= k ; j ++) {
        for(ll i = 0 ; (i + (1ll << j)) <= n ; i++) {
            dp[i][j] = max(dp[i][j - 1] , max(dp[i + (1ll << (j - 1))][j - 1] , max(st[i][j - 1] - stMx[i][j - 1] , st[i + (1ll << (j - 1))][j - 1] -  stMx[i + (1ll << (j - 1))][j - 1])));
        }
    }
}

void query(ll l , ll r) {
    ll j = log2(r - l  + 1);
    ans = max(dp[l][j] , dp[r - (1ll << j) + 1][j]);
    cout << ans << endl;
}

int main() {
    fast_io
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    calcSparseTable();
    query(0 , n - 1);

    return 0;
}

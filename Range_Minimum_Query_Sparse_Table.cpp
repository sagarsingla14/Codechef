#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100000
#define k 25

ll arr[100001] = {0};
ll st[MAX][k];
ll n , q;

void calcSparseTable() {
    for(ll i = 0 ; i < n ; i++) {
        st[i][0] = arr[i];
    }

    for(ll j = 1 ; j <= k ; j ++) {
        for(ll i = 0 ; (i + (1ll << j)) <= n ; i++) {
            st[i][j] = min(st[i][j - 1] , st[i + (1ll << (j - 1))][j - 1]);
        }
    }
}

void query(ll l , ll r) {
    ll j = log2(r - l + 1);
    ll ans = min(st[l][j] , st[r - (1ll << j) + 1][j]);
    cout << ans << endl;
}

int main() {
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }
    calcSparseTable();
    cin >> q;
    while(q--) {
        ll l , r;
        cin >> l >> r;
        query(l , r);
    }
    return 0;
}

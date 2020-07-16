#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100000
#define K 25

// ll n;
// ll st[MAX][K + 1];
// ll arr[MAX] = {0};
ll dp[MAX] = {0};


const int maxn = 1 << 18;
pair<ll , ll> tree[maxn * 2];

void build(const vector <ll> &a , ll n) {
    for (ll i = 0; i < n; i++) tree[maxn + i] = {a[i], i};
    for (ll i = maxn - 1; i > 0; i--)
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

ll get(ll l, ll r) {
    pair<ll , ll> ans{-1, -1};
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, tree[l++]);
        if (r & 1) ans = max(ans, tree[--r]);
    }
    return ans.second;
}

// IS MY SPARSE TABLE WORKIN FINE ?
// void calcSparseTable() {
//     for(ll i = 0 ; i < n ; i++) {
//         st[i][0] = i;
//     }
//     for(ll j = 1 ; j <= K ; j++) {
//         for(ll i = 0 ; (i + (1ll << j)) <= n ; i++) {
//             if(arr[st[i][j - 1]] >= arr[st[i + (1ll << (j - 1))][j - 1]]) {
//                 st[i][j] = st[i][j - 1];
//             }
//             else{
//                 st[i][j] = st[i + (1ll << (j - 1))][j - 1];
//             }
//         }
//     }
// }

// ll query(ll l , ll r) {
//     ll lg = log2(r - l + 1);
//     ll index = max(st[l][lg] , st[r - (1ll << lg) + 1][lg]);
//
//     return index;
// }


void calcDp(ll n , vector <ll> &arr) {
    memset(dp , 0 , sizeof(dp));
    dp[n - 1] = 0;

    for(ll i = n - 2 ; i >= 0 ; i--) {
        ll index = get(i + 1 , arr[i]);
        // cout << "Query " << (i + 1) << " " << arr[i] << " " << index << endl;
        dp[i] = dp[index] + (n - 1 - i) - (arr[i] - index);
    }
}

void print(ll n) {
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++) {
        sum += dp[i];
    }
    cout << sum << endl;
}

int main() {
    fast_io

    ll n;
    cin >> n;
    vector <ll> arr(n);
    for(ll i = 0 ; i < n - 1 ; i++) {
        cin >> arr[i];
        arr[i] --;
    }
    arr[n - 1] = n - 1;

    build(arr , n);

    // for(ll i = 0 ; i < n ; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // calcSparseTable();
    calcDp(n , arr);
    print(n);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100001
#define K 25

ll n;
ll st[MAX][K + 1];
ll arr[MAX] = {0};
ll dp[MAX] = {0};

void calcSparseTable() {
    for(ll i = 0 ; i < n ; i++) {
        st[i][0] = i;
    }
    for(ll j = 1 ; j <= K ; j++) {
        for(ll i = 0 ; (i + (1ll << j)) <= n ; i++) {
            if(arr[st[i][j - 1]] >= arr[st[i + (1ll << (j - 1))][j - 1]]) {
                st[i][j] = st[i][j - 1];
            }
            else{
                st[i][j] = st[i + (1ll << (j - 1))][j - 1];
            }
        }
    }
}

ll query(ll l , ll r) {
    ll lg = log2(r - l + 1);
    ll index = 0;

    if(arr[st[l][lg]] >= arr[st[r - (1ll << lg) + 1][lg]]) {
        index = st[l][lg];
    }
    else{
        index = st[r - (1ll << lg) + 1][lg];
    }

    return index;
}


void calcDp() {
    memset(dp , 0 , sizeof(dp));
    dp[n - 1] = 0;

    for(ll i = n - 2 ; i >= 0 ; i--) {
        ll index = query(i + 1 , arr[i]);
        dp[i] = dp[index] + (n - 1 - i) - (arr[i] - index);
    }
}

void print() {
    ll sum = 0;
    for(ll i = 0 ; i < n ; i++) {
        sum += dp[i];
    }
    cout << sum << endl;
}

int main() {
    fast_io

    cin >> n;
    for(ll i = 0 ; i < n - 1 ; i++) {
        cin >> arr[i];
        arr[i] --;
    }
    arr[n - 1] = n - 1;

    calcSparseTable();
    calcDp();
    print();

    return 0;
}

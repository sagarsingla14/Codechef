#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1100000
#define k 21

string str;
ll st[k][MAX];
ll n , q;

void calcSparseTable() {
    st[0][0]=0;

    for(ll i = 0 ; i < n ; i++) {
        if(str[i] == '(') {
            st[0][i+1] = st[0][i] + 1;
        }
        else {
             st[0][i+1] = st[0][i] - 1;
         }
    }

    for(ll j = 0 ; j < 20 ; j++) {
        for(ll i = 0 ; (i + (1 << j)) <= n ; i++) {
            st[j + 1][i] = min(st[j][i] , st[j][i + (1 << j)]);
        }
    }
}

ll query(ll l , ll r) {
    ll ans = 0;
    ll j = log2(r - l);
    ans = min(st[j][l] , st[j][r - (1ll << j) + 1]);
    return ans;
}

int main() {

    cin >> str;
    n = str.length();

    calcSparseTable();

    cin >> q;
    while(q--) {
        ll l , r;
        cin >> l >> r;
        l --;
        ll ans = (r - l) - st[0][l] - st[0][r] + 2 * query(l , r);
        cout << ans << endl;
    }
    return 0;
}

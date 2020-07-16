#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n , q , x , val;
ll arr[1000001] = {0};
ll st[4000001] = {0};

void buildST(ll left , ll right , ll root) {
    if(left == right) {
        st[root] = arr[left];
        return ;
    }

    ll mid = (left + right) / 2;
    buildST(left , mid , 2 * root);
    buildST(mid + 1 , right , 2 * root + 1);
    st[root] = st[2 * root] + st[2 * root + 1];
}

void update(ll left , ll right , ll root) {
    if(val < left || val > right) {
        return;
    }

    st[root]++;

    if(left != right) {
        ll mid = (left + right) / 2;
        update(left , mid , 2 * root);
        update(mid + 1 , right , 2 * root + 1);
    }
}

ll remove(ll left , ll right , ll root , ll diff) {
    if(left == right) {
        st[root] --;
        return left;
    }

    ll mid = (left + right) / 2;
    ll cur = 0;
    if(st[2 * root] >= diff) {
        cur = remove(left , mid , 2 * root , diff);
    }
    else {
        diff -= st[2 * root];
        cur = remove(mid + 1 , right , 2 * root + 1 , diff);
    }

    st[root] = st[2 * root] + st[2 * root + 1];
    return cur;
}

void printAns() {

    ll ans = -1;
    for(ll i = 1 ; i <= n ; i++) {
        if(arr[i] > 0) {
            ans = i;
            break;
        }
    }
    if(ans == -1) {
        cout << 0 << endl;
    }
    else{
        cout << ans << endl;
    }
}

int main() {
    fast_io
    cin >> n >> q;

    for(ll i = 0 ; i < n ; i++) {
        cin >> x;
        arr[x] ++;
    }

    buildST(1 , n , 1);

    while(q--) {
        cin >> val;
        if(val > 0) {
            update(1 , n , 1);
            arr[val] ++;
        }
        else{
            val = abs(val);
            ll xx = val;
            ll temp = remove(1 , n , 1 , xx);
            cout << temp << endl;
            arr[temp] --;
        }
    }
    printAns();
    return 0;
}

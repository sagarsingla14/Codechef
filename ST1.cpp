#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void buildst(ll low , ll high , ll arr[] , ll st[] , ll pos) {
    // cout << low << " " << high << endl;
    if(low == high) {
        st[pos] = arr[low];
        return ;
    }
    ll mid = (low + high) / 2;
    buildst(low , mid , arr , st , 2 * pos + 1);
    buildst(mid + 1  , high , arr , st , 2 * pos + 2);
    st[pos] = min(st[2 * pos + 1] , st[2 * pos + 2]);
}

void update(ll low , ll high , ll index , ll val , ll pos , ll arr[] , ll st[]) {
    if(low == high) {
        st[pos] = val;
        return;
    }
    ll mid = (low + high) / 2;
    if(index <= mid) {
        update(low , mid , index , val ,  2 * pos + 1 , arr , st);
    }
    else{
        update(mid + 1 , high , index , val ,  2 * pos + 2 , arr , st);
    }

    st[pos] = min(st[2 * pos + 1] , st[2 * pos + 2]);
}

ll queryst(ll qlow , ll qhigh , ll low , ll high , ll arr[] , ll st[] , ll pos) {
    if(qlow > high || qhigh < low) {
        return INT_MAX;
    }
    if(low >= qlow && high <= qhigh) {
        return st[pos];
    }
    ll mid = (low + high) / 2;
    return min(queryst(qlow , qhigh , low , mid , arr , st , 2 * pos + 1) , queryst(qlow , qhigh , mid + 1 , high , arr , st , 2 * pos + 2));
}

int main() {
    ll n , m ;
    cin >> n >> m;
    ll stsize = 0;
    if(pow(2 , log2(n)) == n) {
        stsize = 2 * n - 1;
    }
    else{
        stsize = 2 * pow(2 , log2(n) + 1) - 1;
    }

    ll arr[n] = {0};
    ll st[stsize] = {0};

    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    buildst(0 , n - 1 , arr , st , 0);
    while(m--) {
        char q;
        cin >> q;
        if(q == 'u') {
            ll index , val;
            cin >> index >> val;
            index --;
            update(0 , n - 1 , index , val , 0 , arr , st);
        }
        else{
            ll l , r;
            cin >> l >> r;
            ll result = queryst(l - 1 , r - 1 , 0 , n - 1 , arr , st , 0);
            cout << result << endl;
        }
    }
    return 0;
}

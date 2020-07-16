#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll st[550000];
ll arr[500000];
ll maxlevel ;
void buildst(ll low , ll high , ll pos) {
    if(low == high) {
        st[pos] = arr[low];
        return ;
    }
    ll mid = (low + high) / 2;

    buildst(low , mid , 2 * pos + 1);
    buildst(mid + 1 , high , 2 * pos + 2);
    ll level = log2(pos);
    if(abs(level - maxlevel) % 2) {
        st[pos] = st[2 * pos + 1] | st[2 * pos + 2];
    }
    else{
        st[pos] = st[2 * pos + 1] ^ st[2 * pos + 2];
    }
}

ll queryst(ll qlow , ll qhigh , ll low , ll high , ll pos) {
    if(qlow > high || qhigh < low) {
        return 0;
    }
    if(qlow <= low && qhigh >= high) {
        return st[pos];
    }
    ll level = log2(pos);
    ll mid = (low + high) / 2;
    if(abs(level - maxlevel) % 2) {
        return queryst(qlow , qhigh , low , mid , 2 * pos + 1) | queryst(qlow , qhigh , mid + 1 , high , 2 * pos + 2);
    }
    else{
        return queryst(qlow , qhigh , low , mid , 2 * pos + 1) ^ queryst(qlow , qhigh , mid + 1 , high , 2 * pos + 2);
    }
}
int main() {
    ll n , q;
    cin >> n >> q;
    // ll stsize = 2 * n - 1;
    // ll arr[n] = {0};
    maxlevel = log2(2 * pow(2 , n) - 1) +  1;

    for(ll i = 0 ; i < pow(2 , n) ; i ++) {
        cin >> arr[i];
    }
    buildst(0 , pow(2 , n) - 1 , 0);

    // for(ll i = 0 ; i < 2 * pow(2 , n) - 1 ; i ++) {
    //     cout << st[i] << " ";
    // }
    // cout << endl;
    while(q--) {
        ll l , r;
        cin >> l >> r;
        l-- , r--;
        ll result = queryst(l , r , 0 , pow(2 , n) - 1 , 0);
        cout << result << endl;
    }
    return 0;
}

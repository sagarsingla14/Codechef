#include <bits/stdc++.h>
#define ll long long int
using namespace std;


struct Node {
    ll left ;
    ll right ;
};

vector <Node *> tree(100000);
ll ans;

void ConstructTree(ll arr[] , ll l , ll r , ll node) {
    if(l == r) {
        Node *temp = new Node();
        temp -> left = arr[l];
        temp -> right = arr[l];
        tree[node] = temp;
        return ;
    }

    ll mid = (l + r) / 2;
    ConstructTree(arr , l , mid , 2 * node + 1);
    ConstructTree(arr , mid + 1 , r , 2 * node + 2);
    Node *temp = new Node();
    temp -> left = tree[2 * node + 1] -> right;
    temp -> right = tree[2 * node + 2] -> left;
    tree[node] = temp;
}

void findAns(ll l , ll r , ll start , ll end , ll val , ll node) {
    // cout << l << " " << r << " " << start << " " << end << " " << val << " " << node << endl;
    ll mid = (l + r) / 2;
    ll leftstart = l;
    ll leftend = mid;
    ll rightstart = mid + 1;
    ll rightend = r;
    if(l == r) {
        return ;
    }
    else if(leftend < start || leftstart > end) {
        // right check
        findAns(mid + 1 , r , start , end , val , 2 * node + 2);
        return ;
    }
    else if(rightend < start || rightstart > end){
        // leftcheck
        findAns(l , mid , start , end , val , 2 * node + 1);
        return ;
    }
    else{
        ll valleft = tree[node] -> left;
        ll valright = tree[node] -> right;
        if(valleft > valright) {
            swap(valleft , valright);
        }

        if(valleft <= val && valright >= val) {

            ans ++;
            cout << ans << " " << valleft << " " << valright << endl;

        }

        findAns(l , mid , start , end , val , 2 * node + 1);
        findAns(mid + 1 , r , start , end , val , 2 * node + 2);
    }
}

int main(){
    ll t;
    cin >> t;
    while(t--) {
        ll n , q;
        cin >> n >> q;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        ll size = log2(n);
        if(pow(2 , size) < n) {
            size ++;
        }

        size = 2 * pow(2 , size) - 1;
        ll node = 0 , l = 0 , r = n - 1;
        ConstructTree(arr , l , r , node);

        for(ll i = 0 ; i < size ; i++) {
            cout << tree[i] -> left << " " << tree[i] -> right << endl;
        }

        while(q--) {
            ans = 0;
            ll start , end , val;
            cin >> start >> end >> val;
            start --;
            end --;

            if(start == end) {
                if(val == arr[start]) {
                    cout << 1 << endl;
                }
                else{
                    cout << 0 << endl;
                }
                continue;
            }
            node = 0;
            findAns(0 , n - 1 , start , end , val , node);
            cout << ans << endl;
        }

        tree.clear();
    }
    return 0;
}

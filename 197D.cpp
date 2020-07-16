#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[250000];
ll st[500000];
ll n , m;
ll operation;

void processSegmentTree(ll root){
    ll curLevel = log2(root + 1);
    // cout << "operation Curlevel root -> " << operation << " " << curLevel << " " << root << endl;
    if(operation) {
        if(curLevel % 2 == 0) {
            st[root] = st[2 * root + 1] | st[2 * root + 2];
        }
        else{
            st[root] = st[2 * root + 1] ^ st[2 * root + 2];
        }
    }
    else{
        if(curLevel % 2) {
            // cout << "root before after -> " << root << " " << st[root] << " ";
            st[root] = st[2 * root + 1] | st[2 * root + 2];
            // cout << st[root] << endl;

        }
        else{
            // cout << "root before after -> " << root << " " << st[root] << " ";
            st[root] = st[2 * root + 1] ^ st[2 * root + 2];
            // cout << st[root] << endl;
        }
    }
}

void formSegmentree(ll left , ll right , ll root) {
    // Working Fine
    if(left == right) {
        st[root] = arr[left];
        return ;
    }

    ll mid = (left + right) / 2;
    formSegmentree(left , mid , 2 * root + 1);
    formSegmentree(mid + 1 , right , 2 * root + 2);

    processSegmentTree(root);
}


void updateSegmentTree(ll index , ll val , ll left , ll right , ll root) {
    if(left == right) {
        // cout << "Index val -> " << left << " " << val << " " << root << endl;
        st[root] = val;
        arr[left] = val;
        return ;
    }

    ll mid = (left + right) / 2;
    if(index <= mid) {
        // cout << "left val -> " << left << " " << mid << " " << root << endl;

        updateSegmentTree(index , val , left , mid , 2 * root + 1);
    }
    else{
        // cout << "right val -> " << mid + 1 << " " << right << " " << root << endl;

        updateSegmentTree(index , val , mid + 1 , right , 2 * root + 2);
    }

    processSegmentTree(root);
}

int main() {

    memset(arr , 0 , sizeof(arr));
    memset(st , 0 , sizeof(st));
    cin >> n >> m;
    operation = (n % 2);
    n = pow(2 , n);
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    ll stsize = 2 * n - 1;
    st[stsize] = {0};
    formSegmentree(0 , n - 1 , 0);


    while(m --) {
        ll index , val;
        cin >> index >> val;
        index --;
        updateSegmentTree(index , val , 0 , n - 1 , 0);

        cout << st[0] << endl;
    }
    cout << endl;
    
    return 0;
}

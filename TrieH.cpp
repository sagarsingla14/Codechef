#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
    bool isEnd;
    map <char , Node*> child;
    ll nodeVal;
};

void insert(Node *root , string str , ll val) {
    ll l = str.length();
    Node *cur = root;
    for(ll i = 0 ; i < l ; i++) {
        if(cur -> child[str[i]]) {
            cur = cur -> child[str[i]];
            cur -> nodeVal = max(cur -> nodeVal , val);
        }
        else{
            Node *temp = new Node();
            temp -> isEnd = false;
            cur -> child[str[i]] = temp;
            cur = cur -> child[str[i]];
            cur -> nodeVal = val;
        }
    }
    cur -> isEnd = true;
}

ll calc(Node *root , string str) {
    ll l = str.length();
    ll flag = 0;
    for(ll i = 0 ; i < l ; i++) {
        if(!(root -> child[str[i]])) {
            flag = 1;
            break;
        }
        root = root -> child[str[i]];
    }
    if(flag) {
        return -1;
    }
    return root -> nodeVal;

}

int main() {
    ll n , q;
    cin >> n >> q;
    Node *root = new Node();
    for(ll i = 0 ; i < n ; i++) {
        string str;
        ll val;
        cin >> str >> val;
        insert(root , str , val);
    }
    while(q--) {
        string str;
        cin >> str;
        ll ans = calc(root , str);
        cout << ans << endl;
    }
    return 0;
}

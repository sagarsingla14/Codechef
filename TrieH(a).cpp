#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
    bool isEnd;
    map <char , Node*> child;
};

void insert(Node *root , string str , ll ans) {
    // cout << 1 << endl;
    ll l = str.length();
    Node *cur = root;
    for(ll i = 0 ; i < l ; i++) {
        cout << 2 << endl;

        if(cur -> child[str[i]]) {
            cur = cur -> child[str[i]];
        }
        else{
            Node *temp = new Node();
            temp -> isEnd = false;
            cur -> child[str[i]] = temp;
            cur = cur -> child[str[i]];
            ans ++;
        }
    }
    cur -> isEnd = true;
}

int main() {
    ll n;
    cin >> n;
    Node *root = new Node();
    ll ans = 1;
    for(ll i = 0 ; i < n ; i++) {
        string str;
        cin >> str ;
        insert(root , str , ans);
    } 
    cout << ans << endl;
    return 0;
}

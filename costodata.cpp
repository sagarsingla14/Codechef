#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll ans ;

struct Node {
    bool isEnd;
    map <char , Node*> child;
};

void insert(string str , Node *root) {
    ll l = str.length();
    for(ll i = 0 ; i < l ; i++) {
        if(root -> child[str[i]]) {
            root = root -> child[str[i]];
        }
        else {
            Node *temp = new Node();
            temp -> isEnd = false;
            root -> child[str[i]] = temp;
            root = root -> child[str[i]];
            ans ++;
        }
    }
    root -> isEnd = true;
}

int main() {
    ll n;
    cin >> n;
    ans = 0;
    Node *root = new Node();
    while(n--) {
        string str;
        cin >> str;
        insert(str , root);
    }
    cout << ++ans << endl;
}

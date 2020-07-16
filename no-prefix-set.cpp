#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll ok = 1;
string ans;
ll n;

struct Node {
    map <char , Node*> child;
    bool isEnd;
};

void insert(string str , ll index , Node *root) {
    ll l = str.length();
    if(index == l) {
        return ;
    }
    if(root -> isEnd == true) {
        ok = 0;
    }
    char cur = str[index];
    if(root -> child[cur] != NULL) {
        root = root -> child[cur];
        if(index == l - 1) {
            if(root -> child.size() > 0 || root -> isEnd) {
                ok = 0;
            }
        }
        insert(str , index + 1 , root);
    }
    else{
        Node *nextNode = new Node();
        if(index == l - 1) {
            nextNode -> isEnd = true;
        }
        else {
            nextNode -> isEnd = false;
        }
        root -> child[cur] = nextNode;
        root = root -> child[cur];
        insert(str , index + 1 , root);
    }
}

int main() {
    cin >> n;
    ans = "";
    ok = 1;

    Node *root = new Node();
    for(ll i = 0 ; i < n ; i++) {
        string str;
        cin >> str;
        if(!ok) {
            continue;
        }
        else{
            insert(str , 0 , root);
            if(!ok) {
                ans = str;
            }
        }
    }

    if(!ok) {
        cout << "BAD SET" << endl;
        cout << ans << endl;
    }
    else{
        cout << "GOOD SET" << endl;
    }
    return 0;
}

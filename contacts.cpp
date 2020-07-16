#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
ll ans = 0;

struct Node {
    map <char , ll> freq;
    map <char , Node*> child;
};

void insert(string str , ll index , Node *root) {
    ll l = str.length();
    if(index == l) {
        return ;
    }
    char cur = str[index];
    if(root -> child[cur] != NULL) {
        root -> freq[cur] ++;
        root = root -> child[cur];
        insert(str , index + 1 , root);
    }
    else{
        Node *nextNode = new Node();
        root -> freq[cur] = 1;
        root -> child[cur] = nextNode;
        root = root -> child[cur];
        insert(str , index + 1 , root);
    }
}

void findCount(string str , ll index , Node *root) {
    ll l = str.length();
    char cur = str[index];
    if(index == l - 1) {
        ans = root -> freq[cur];
        return;
    }
    if(root -> freq[cur] == 0) {
        ans = 0;
        return ;
    }
    else {
        root = root -> child[cur];
        findCount(str , index + 1 , root);
    }
}

int main() {
    ll n;
    cin >> n;
    Node *root = new Node();

    for(ll i = 0 ; i < n ; i++) {
        string q , str;
        cin >> q >> str;
        if(q == "add") {
            insert(str , 0 , root);
        }
        else {
            ans = 0;
            findCount(str , 0 , root);
            cout << ans << endl;
        }
    }
    return 0;
}

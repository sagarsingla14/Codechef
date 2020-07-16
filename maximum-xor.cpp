#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string ans;

struct Node{
    map <char , Node*> mp;
};

string convertToBinary(ll x) {
    string str = "";
    for(ll j = 0 ; j < 64 ; j++) {
        if((x & (1ll << 63ll - j)) >= 1) {
            str += '1';
        }
        else {
            str += '0';
        }
    }
    return str;
}

void insert(string str , ll index , Node *root) {
    if(index == 64) {
        return;
    }
    char bit = str[index];
    if(root -> mp.find(bit) != root -> mp.end()) {
        insert(str , index + 1 , root -> mp[bit]);
    }
    else{
        Node *child = new Node();
        root -> mp[bit] = child;
        insert(str , index + 1 , root -> mp[bit]);
    }
}

void findMaxXor(string str , ll index , Node *root) {
    if(index == 64) {
        return ;
    }
    char bit = str[index];
    if(bit == '0') {
        if(root -> mp.find('1') != root -> mp.end()) {
            ans += '1';
            findMaxXor(str , index + 1 , root -> mp['1']);
        }
        else{
            ans += '0';
            findMaxXor(str , index + 1 , root -> mp['0']);
        }
    }
    if(bit == '1') {
        if(root -> mp.find('0') != root -> mp.end()) {
            ans += '1';
            findMaxXor(str , index + 1 , root -> mp['0']);
        }
        else{
            ans += '0';
            findMaxXor(str , index + 1 , root -> mp['1']);
        }
    }
}

void printAns() {
    ll xr = 0;
    for(ll i = 0 ; i < 64 ; i++) {
        if(ans[i] == '1') {
            xr += (1ll << (63ll - i));
        }
    }
    cout << xr << endl;
}

int main() {
    ll n;
    cin >> n;
    Node *root = new Node();
    ll arr[n] = {0};
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
        string str = convertToBinary(arr[i]);
        insert(str , 0 , root);
    }

    ll q;
    cin >> q;
    while(q--) {
        ll x;
        cin >> x;
        string str = convertToBinary(x);
        ans = "";
        findMaxXor(str , 0 , root);
        printAns();
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string ans;
vector <ll> res;

struct Node{
    map <char , Node*> mp;
};

string convertToBinary(ll x) {
    string str = "";
    for(ll j = 0 ; j < 32 ; j++) {
        if((x & (1 << 31 - j)) >= 1) {
            str += '1';
        }
        else {
            str += '0';
        }
    }
    return str;
}

void insert(string str , ll index , Node *root) {
    if(index == 32) {
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
    if(index == 32) {
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
    for(ll i = 0 ; i < 32 ; i++) {
        if(ans[i] == '1') {
            xr += (1 << (31 - i));
        }
    }
    res.push_back(xr);
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

    ll q = n;
    ll i = 0;
    while(q--) {
        ll x = arr[i];
        string str = convertToBinary(x);
        ans = "";
        findMaxXor(str , 0 , root);
        printAns();
         i ++;
    }

    cout << *max_element(res.begin() , res.end()) << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

struct Node {
    map <ll , Node*> mp;
    ll cnt = 0;
};

ll ans = 0;
Node *head;

void insert(ll x) {
    Node *cur = head;
    for(ll i = 31 ; i >= 0 ; i--) {
        ll curBit = (x >> i) & 1;
        if(cur -> mp[curBit]) {
            cur = cur -> mp[curBit];
        }
        else {
            Node *next = new Node();
            cur -> mp[curBit] = next;
            cur = next;
        }
        cur -> cnt ++;
    }
}

void remove(ll x) {
    Node *cur = head;
    for(ll i = 31 ; i >= 0 ; i--) {
        ll curBit = (x >> i) & 1;
        if(cur -> mp[curBit]) {
            cur = cur -> mp[curBit];
            cur -> cnt --;
        }
    }
}

void calcXor(ll x) {
    Node *cur = head;
    for(ll i = 31 ; i >= 0 ; i--) {
        ll curBit = (x >> i) & 1;
        if(cur -> mp[!curBit] && cur -> mp[!curBit] -> cnt > 0) {
            cur = cur -> mp[!curBit];
            ans += (1ll << i);
        }
        else{
            cur = cur -> mp[curBit];
        }
    }
}

int main() {
    ll n;
    cin >> n;

    head = new Node();
    insert(0);

    for(ll i = 0 ; i < n ; i++) {
        char s;
        ll num;
        cin >> s >> num;
        if(s == '+') {
            insert(num);
        }
        else if(s == '-') {
            remove(num);
        }
        else{
            ans = 0;
            calcXor(num);
            cout << ans << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
struct Node {
    ll data;
    Node *left;
    Node *right;
};

int main() {
    vector <Node *> v;
    Node *node = new Node();


    node -> data = 10;
    node -> left = NULL;
    node -> right = NULL;
    v.push_back(node);
    // v[0] -> left = v[0] -> right;
    cout << v[0] -> data << endl;
    cout << v[0] -> right << endl;
    cout << v[0] -> left << endl;

    // Example
    ll var = 10;
    ll *ptr = &var;
    cout << *ptr << endl;
}

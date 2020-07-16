#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct Node {
    bool isEnd;
    map <char , Node* > child;
};

int main() {
    Node *temp = new Node();
    Node *temp1 = new Node();
    temp -> isEnd = false;
    temp -> child['a'] = temp1;
    
}

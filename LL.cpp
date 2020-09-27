#include <bits/stdc++.h>
#define ll long long int
using namespace std;


struct Node {
    ll data;
    Node *next;
};

int main() {
    Node *head = NULL;

    if(!head) {
        head = new Node();
        head -> data = 1;
        head -> next = NULL;
    }

    cout << head -> data << endl;
    free(head);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct Node {
    ll a , b;
};

struct comp {
   bool operator() (Node *p1 , Node *p2) {
       if((p1 -> b - p1 -> a) == (p2 -> b - p2 -> a)) {
           return p1 -> a > p2 -> b;
       }
       else {
           return (p1 -> b - p1 -> a) < (p2 -> b - p2 -> a);
       }
   }
};

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        ll ans[n + 1] = {0};
        priority_queue <Node* , vector <Node*> , comp> pq;

        Node *node = new Node();
        node -> a = 1;
        node -> b = n;
        pq.emplace(node);

        ll cnt = 0;
        while(!pq.empty()) {
            cnt ++;
            Node *cur = pq.top();
            pq.pop();

            ll x = cur -> a;
            ll y = cur -> b;

            if((y - x + 1) % 2 != 0) {
                ans[(x + y) / 2] = cnt;
                ll mid = (x + y) / 2;
                if(mid - 1 >= x) {
                    Node *node = new Node();
                    node -> a = x;
                    node -> b = mid - 1;
                    pq.emplace(node);
                }
                if(mid + 1 <= y) {
                    Node *node = new Node();
                    node -> a = mid + 1;
                    node -> b = y;
                    pq.emplace(node);
                }
            }
            else{
                ans[(x + y - 1) / 2] = cnt;
                ll mid = (x + y - 1) / 2;
                if(mid - 1 >= x) {
                    Node *node = new Node();
                    node -> a = x;
                    node -> b = mid - 1;
                    pq.emplace(node);
                }
                if(mid + 1 <= y) {
                    Node *node = new Node();
                    node -> a = mid + 1;
                    node -> b = y;
                    pq.emplace(node);
                }
            }
        }

        for(ll i = 1 ; i <= n ; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    queue <ll> q;
    while(t--) {
        ll x;
        cin >> x;
        if(x == 1) {
            cin >> x;
            q.push(x);
        }
        else if(x == 2) {
            q.pop();
        }
        else{
            cout << q.front() << endl;
        }
    }
    return 0;
}

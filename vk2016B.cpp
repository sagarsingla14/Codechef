#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , d , h;

void printTree() {
    for(ll i = 1 ; i <= h ; i++) {
        cout << i << " " << i + 1 << endl;
    }

    ll ok = 1;
    ll diff = abs(h - d);
    if(diff == 0) {
        ok = 0;
    }
    ll next = 0;
    if(ok) {
        for(ll i = 1 ; i <= diff ; i++) {
            if(i == 1) {
                cout << 1 << " " << h + 2 << endl;
                next = h + 2;
            }
            else{
                cout << next << " " << next + 1 << endl;
                next ++;
            }
        }
        ll rem = abs(n - d - 1);
        for(ll i = 0 ; i < rem ; i++) {
            cout << 1 << " " << d + 2 + i << endl;
        }
    }
    else{
        ll rem = abs(n - h - 1);
        for(ll i = 0 ; i < rem ; i++) {
            cout << 2 << " " << h + 2 + i << endl;
        }
    }
}

int main() {
    cin >> n >> d >> h;
    if(d > 2 * h || (n >= 3 && d == 1)) {
        cout << -1 << endl;
    }
    else {
        printTree();
    }
    return 0;
}

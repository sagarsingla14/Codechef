#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n , m;
        cin >> n;
        ll p[n] = {0};
        ll pe = 0, qe = 0, po = 0 , qo = 0;
        for(ll i = 0 ; i < n ; i++) {
            cin >> p[i];
            if(p[i]%2) {
                po ++;
            }
            else{
                pe ++;
            }
        }
        cin >>  m;
        ll q[m] = {0};

        for(ll i = 0 ; i < m ; i++) {
            cin >> q[i];
            if(q[i] % 2) {
                qo ++;
            }
            else{
                qe ++;
            }
        }

        cout << qe * pe + qo * po << endl;
    }
    return 0;
}

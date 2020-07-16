#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
const ll mod = 1e9 + 7;

int main() {
    ll t;
    cin >> t;

    while(t--) {
        set <string> s;
        map <string , ll> a , b;
        map <pair <string , string> , ll> e;
        ll ok = 1;
        map <string , string> graph;
        for(ll i = 0;  i < 3 ; i++) {
            string aa , bb;
            cin >> aa >> bb;
            if(e[{aa , bb}] || e[{bb , aa}]) {
                ok = 0;
            }
            e[{aa , bb}] = 1;
            e[{bb , aa}] = 1;
            if(aa == bb) {
                ok = 0;
            }
            s.insert(aa);
            s.insert(bb);
            a[aa] ++;
            b[bb] ++;
        }

        if(s.size() == 3 && ok) {
            if(a.size() == b.size())   {
                cout << "Valid" << endl;
            }
            else {
                cout << "Invalid" << endl;
            }
        }
        else{
            cout << "Invalid" << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    fast_io

    ll t;
    cin >> t;
    if(t > 26) {
        cout << "OH SHIT" << endl;
        return 0;
    }

    ll ok = 1;
    ll mp[26] = {0};

    while(t--) {
        string str;
        cin >> str;
        
        mp[str[0] - 'a'] ++;
        if(mp[str[0] - 'a'] > 1) {
            ok = 0;
            break;
        }
    }

    if(!ok) {
        cout << "OH SHIT" << endl;
    }
    else{
        cout << "ALL IZZ WELL" << endl;
    }
    return 0;
}

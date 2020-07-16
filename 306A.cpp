#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    string str;
    cin >> str;
    ll n = str.length();
    vector <ll> a , b;
    ll ab = 0 , ba = 0;
    for(ll i = 0 ; i < n - 1 ; i++) {
        if(str[i] == 'A' && str[i + 1] == 'B') {
            ab ++;
            a.push_back(i);
        }
        else if(str[i] == 'B' && str[i + 1] == 'A') {
            ba ++;
            b.push_back(i);
        }
    }

    if(!ab || !ba) {
        cout << "NO" << endl;
    }
    else{
        ll as = a.size();
        ll bs = b.size();
        ll flag = 0;
        if(abs(a[0] - b[bs - 1]) > 1) {
            flag = 1;
        }
        if(abs(a[as - 1] - b[0] > 1)) {
            flag = 1;
        }

        if(flag) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

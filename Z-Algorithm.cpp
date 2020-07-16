#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

string str;
ll n;
ll z[100001] = {0};

void Z_Function() {
    ll l = 0 , r = 0;
    for(ll i = 1 ; i < n ; i++) {
        if(i <= r) {
            z[i] = min(r - i + 1 , z[i - l]);
        }
        while(i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            z[i] ++;
        }

        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main() {
    cin >> str;
    n = str.length();
    Z_Function();

    for(ll i = 0 ; i < n ; i++) {
        cout << z[i] << " ";
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll n;
string in , out;

void file_io() {
    freopen("adihack.txt", "w" , stdout);
}

int main() {
    file_io();
    cout << 1000 << endl;
    for(ll c = 1 ; c <= 1000 ; c ++) {
        cout << 50 << endl;
        for(ll i = 0 ; i < 49 ; i++) {
            cout << 50 << " ";
        }
        cout << 49 << endl;
    }
    return 0;
}

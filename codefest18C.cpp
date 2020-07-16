#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string a , b;
ll ans = 0;
ll n;

int main() {
    cin >> n >> a >> b;
    for(ll i = 0 ; i < n - 1 ; i++) {
        if(a[i] != b[i] && a[i + 1] != b[i + 1] && a[i] == b[i + 1] && a[i + 1] == b[i]) {
            ans ++;
            a[i] = b[i];
            a[i + 1] = b[i + 1];
            i ++;
        }
        else if(a[i] != b[i]) {
            a[i] = b[i];
            ans ++;
        }
    }
    if(a[n - 1] != b[n - 1]) {
        ans ++;
    }
    cout << ans << endl;
    return 0;
}

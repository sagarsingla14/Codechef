#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,x,a,b;
        cin >> n >> x >> a >> b;
        ll d = abs(a - b);
        ll left = min(a,b) - 1;
        ll right = n - max(a,b);

        d += min(x , left);
        x -= min(x , left);

        d += min(x , right);

        cout << d << endl;
    }
    return 0;
}

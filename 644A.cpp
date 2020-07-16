#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
ll t;
ll a , b;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b;
        ll ans = min(max(2 * a , b) , max(2 * b , a));
        ans *= ans;
        cout << ans << endl;
    }
    return 0;
}

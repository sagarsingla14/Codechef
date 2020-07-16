#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

ll ans = 0;

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = 0, rem = 0;

    while(a != 0){
        ans += a;
        rem += a % b;
        // cout << "a ans " << a << " " << ans << " " << rem << endl;
        a /= b;
    }

    ll temp = rem;
    rem = 0;
    if(temp >= b) {
        while(temp != 0){
            rem += temp % b;
            temp /= b;
            ans += temp;
            // cout << "temp ans " << temp << " " << ans << " " << rem << endl;
        }
    }

    temp = rem;
    rem = 0;
    if(temp >= b) {
        while(temp != 0 && temp >= b){
            rem += temp % b;
            temp /= b;
            ans += temp;
            // cout << "temp ans " << temp << " " << ans << " " << rem << endl;
        }
    }

    cout << ans << "\n";
	return 0;
}

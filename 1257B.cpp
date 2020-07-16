#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        if(b <= a) {
            cout << "YES" << endl;
        }
        else{
            if(a % 2) {
                a--;
                if(a == 0) {
                    cout << "NO" << endl;
                    continue;
                }

                ll temp = 3 * a;
                temp /= 2;
                if(temp > a + 1) {
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
            else{
                ll temp = 3 * a;
                temp /= 2;
                if(temp > a) {
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}

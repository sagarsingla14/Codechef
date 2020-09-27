#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll a , b;
    cin >> a >> b;

    ll pa = a , pb = b;
    while(1) {
        if(a >= 2 * b) {
            a -= (a / (2 * b)) * (2 * b);
        }
        if(a == 0) {
            break;
        }
        if(b >= 2 * a) {
            b -= (b / (2 * a)) * (2 * a);
        }
        if(b == 0) {
            break;
        }

        if(pa == a && pb == b) {
            break;
        }
        else{
            pa = a , pb = b;
        }
    }
    cout << a << " " << b << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    ll n , m , a;
    cin >> n >> m >> a;

    ll l = n / a;
    if(n % a) {
        l ++;
    }

    ll b = m / a;
    if(m % a) {
        b ++;
    }

    cout << l * b << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n;

int main() {
    cin >> n;
    if(n == 1) {
        cout << -1 << endl;
    }
    else {
        cout << n << " " << n + 1 << " " << n * (n + 1) << endl;
    }

    return 0;
}

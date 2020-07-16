#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define in int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solveMax(ll n , ll k) {
    ll w = n - (k - 1);
    w = (w * (w - 1)) / 2;
    cout << w << endl;
}

void solveMin(ll n , ll k) {
    ll div = n / k;
    ll rem = n % k;

    ll w1 = (div + 1);
    ll w2 = (div);
    w1 = (w1 * (w1 - 1)) / 2;
    w2 = (w2 * (w2 - 1)) / 2;

    w1 *= rem;
    w2 *= (k - rem);

    cout << w1 + w2 << " ";
}

int main() {
    ll n , k;
    cin >> n >> k;
    solveMin(n , k);
    solveMax(n , k);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    ll n;
    cin >> n;

    bitset <10> bs(n);

    cout << bs << endl;
    cout << bs.any() << endl;
    cout << bs.none() << endl;
    cout << bs.count() << endl;
    cout << bs.size() << endl;
    bs.set(0 , 1);
    cout << (bs[0] ^ 1) << endl;
    cout << bs << endl;
    bs.set();
    cout << bs << endl;
    bs.reset();
    cout << bs << endl;
    bs.flip();
    cout << bs << endl;

    string s = "1010111";
    bitset <8> bs1(s);
    cout << bs1 << endl;

    bitset <1000000> op;

    op.set(0 , 1);
    cout << op << endl;
    cout << (op << 998) << endl;

    return 0;
}

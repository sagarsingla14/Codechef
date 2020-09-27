#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

int main() {
    ld x , y;
    cin >> x >> y;

    ld lx = log2(x);
    ld ly = log2(y);

    ld left = lx * y;
    ld right = ly * x;

    if(left == right) {
        cout << "=" << endl;
    }
    else{
        if(left > right) {
            cout << ">" << endl;
        }
        else{
            cout << "<" << endl;
        }
    }
}

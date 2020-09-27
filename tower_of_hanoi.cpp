#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll cnt = 0;
void solve(ll n , char a , char b , char c) {
    if(n == 1) {
        cnt ++;
        cout << "from " << a << " to " << b << endl;
        return;
    }

    cnt ++;
    solve(n - 1 , a , c , b);
    cout << "from " << a << " to " << b << endl;
    solve(n - 1 , c , b , a);
}

int main() {
    int n;
    cin >> n;
    solve(n , 'A' , 'B' , 'C');
    // cout << cnt << endl;
    return 0;
}

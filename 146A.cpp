#include <iostream>
using namespace std;
#define ll long long int
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll n , ans = 0;
    cin >> n;

    if(n == 1) {
        ans = 1;
    }
    else if(n == 2) {
        ans = 2;
    }
    else if(n == 3) {
        ans = 6;
    }
    else if(n & 1) {
        ans = n * (n - 1) * (n - 2);
    }
    else{
        if(n % 3) {
            ans = max(n * (n - 1) * (n - 3) , (n - 3) * (n - 1) * (n - 2));
        }
        else{
            ans = (n - 3) * (n - 1) * (n - 2);
        }
    }
    cout << ans << endl;
    return 0;
}

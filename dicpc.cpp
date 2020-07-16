#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <map>
#define base 1000000007
#define ll long long int

ll sd(ll n) {
    ll sum = 0;
    while(n) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

int main(){
    ll n , s;
    cin >> n >> s;
    ll num = 0;
    ll l = 1 , r = n;
    while (l <= r) {
        ll mid = r - (r - l) / 2;
        ll sumdigit = sd(mid);
        if(mid - sumdigit >= s) {
            num = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    if(num == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << abs(num - n) + 1 << endl;
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    string a , b;
    cin >> a >> b;
    ll la = a.length();
    ll lb = b.length();

    ll one[lb + 1] = {0};
    ll zero[lb + 1] = {0};
    for(ll i = 0 ; i < lb ; i++) {
        if(b[i] == '1') {
            one[i] = 1;
            zero[i] = 0;
        }
        else{
            one[i] = 0;
            zero[i] = 1;
        }
    }

    for(ll i = lb - 2 ; i >= 0 ; i--) {
        one[i] += one[i + 1];
        zero[i] += zero[i + 1];
    }

    ll i = la - 1;
    ll j = lb - 1;
    ll sum = 0;
    for(ll x = 0 ; x < la ; x++) {
        if(a[i] == '1') {
            ll val = abs(zero[i] - zero[j + 1]);
            sum += val;
        }
        else{
            ll val = abs(one[i] - one[j + 1]);
            sum += val;
        }
        i-- , j--;
    }
    cout << sum << endl;
    return 0;
}

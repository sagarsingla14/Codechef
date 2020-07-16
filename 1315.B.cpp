#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll a , b , p;
        cin >> a>> b >> p;
        string str;
        cin >> str;
        ll l = str.length();

        ll arr[l] = {0};
        ll sum[l] = {0};
        for(ll i = l - 2 ; i >= 0 ; i--) {
            if(str[i] == 'A') {
                arr[i] = a;
            }
            if(str[i] == 'B') {
                arr[i] = b;
            }
        }


        for(ll i = l - 2 ; i >= 0 ; i --) {
            if(arr[i] != arr[i + 1]) {
                sum[i] = sum[i + 1] + arr[i];
            }
            else {
                sum[i] = sum[i + 1];
            }
        }
        ll index = 0;
        for(ll i = l - 1 ; i >= 0 ; i--) {
            if(sum[i] > p) {
                index = i + 2;
                break;
            }
        }
        // cout << endl;
        if(index == 0) {
            cout << 1 << endl;
        }
        else{
            cout << index << endl;
        }
    }
    return 0;
}

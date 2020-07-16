#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n , k , ok = 1;
string str;

int main() {
    cin >> n >> k >> str;
    ll cnt = 0;
    for(ll i = 0 ; i < n / 2 ; i++) {
        if(str[i] != str[n - 1 - i]) {
            cnt ++;
        }
    }
    if(cnt > k) {
        cout << -1 << endl;
    }
    else {
        ll arr[n] = {0};
        if(n % 2 == 0) {
            for(ll i = 0; i < n / 2 ; i++) {
                if(str[i] != str[n - i - 1]) {
                    if(str[i] > str[n - i - 1]) {
                        str[n - i - 1] = str[i];
                        arr[n - i - 1] = 1;
                    }
                    else{
                        str[i] = str[n - i - 1];
                        arr[i] = 1;
                    }
                    k --;
                }
            }

            for(ll i = 0 ; i < n / 2 ; i ++) {
                if(str[i] != '9') {
                    k += arr[i];
                    k += arr[n - i - 1];
                    if(k >= 2) {
                        str[i] = '9';
                        str[n - i - 1] = '9';
                        k -= 2;
                    }
                    else{
                        k -= arr[i];
                        k -= arr[n - i - 1];
                    }
                }
            }
        }
        else{
            for(ll i = 0 ; i <= (n / 2 - 1) ; i++) {
                if(k <= 0) {
                    break;
                }
                if(str[i] != str[n - i - 1]) {
                    if(str[i] > str[n - i - 1]) {
                        str[n - i - 1] = str[i];
                        arr[n - i - 1] = 1;
                    }
                    else{
                        str[i] = str[n - i - 1];
                        arr[i] = 1;
                    }
                    k --;
                }
            }
            for(ll i = 0 ; i <= (n / 2 - 1) ; i ++) {
                if(str[i] != '9') {
                    k += arr[i];
                    k += arr[n - i - 1];
                    if(k >= 2) {
                        str[i] = '9';
                        str[n - i - 1] = '9';
                        k -= 2;
                    }
                    else{
                        k -= arr[i];
                        k -= arr[n - i - 1];
                    }
                }
            }

            if(str[n / 2] != '9' && k >= 1) {
                str[n / 2] = '9';
            }
        }
        cout << str << endl;
    }
    return 0;
}

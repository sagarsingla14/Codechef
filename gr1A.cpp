#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll b , k;
ll arr[500001];

int main() {
    cin >> b >> k;
    for(ll i = 0 ; i < k ; i ++) {
        cin >> arr[i];
    }

    if(b % 2) {
        ll odd = 0;
        for(ll i = 0 ; i < k - 1 ; i++) {
            if(arr[i] % 2) {
                odd ++;
            }
        }
        if(arr[k - 1] % 2) {
            odd ++;
        }
        if(odd % 2 == 0) {
            cout << "even" << endl;
        }
        else{
            cout << "odd" << endl;
        }
    }
    else{
        ll odd = 0;
        if(arr[k - 1] % 2) {
            odd ++;
        }
        if(odd % 2 == 0) {
            cout << "even" << endl;
        }
        else{
            cout << "odd" << endl;
        }
    }
    return 0;
}

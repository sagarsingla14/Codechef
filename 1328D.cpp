#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll arr[n] = {0};
        for(ll i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        ll color[n] = {0};

        ll val = 1;
        color[0] = 1;
        for(ll i = 1 ; i < n ; i++) {
            if(arr[i] != arr[i - 1]) {
                if(val == 1) {
                    val ++;
                    color[i] = val;
                }
                else if(val == 2) {
                    val --;
                    color[i] = val;
                }
            }
            else{
                color[i] = val;
            }
        }

        ll prev = color[n - 1];

        if(arr[n - 1] != arr[0]) {
            if(color[0] == color[n - 1]) {
                color[n - 1] = 3;
            }
        }

        if(color[n - 1] == 3) {
            ll check = 0;
            ll index = -1 ;
            for(ll i = n - 1 ; i >= 1 ; i--) {
                if(color[i] == color[i - 1]) {
                    check = 1;
                    index = i;
                    break;
                }
            }

            if(check) {
                for(ll i = index ; i < n - 1 ; i++) {
                    if(color[i] == 2) {
                        color[i] = 1;
                    }
                    else{
                        color[i] = 2;
                    }
                }
                if(prev == 1) {
                    color[n - 1] = 2;
                }
                else{
                    color[n - 1] = 1;
                }
            }
        }

        set <ll> s;
        for(ll i = 0 ; i < n ; i++) {
            s.insert(color[i]);
        }
        cout << s.size() << endl;

        for(ll i = 0 ; i < n ; i++) {
            cout << color[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll k , a , b;
    cin >> k >> a >> b;
    string str;
    cin >> str;
    ll n = str.length();
    ll val = n / k;
    ll mod = n % k;
    ll arr[k] = {0};
    for(ll i = 0 ; i < k ; i++) {
        arr[i] = val;
    }
    for(ll i = 0 ; i < mod ; i++) {
        arr[i] ++;
    }
    if(val < a) {
        cout << "No solution" << endl;
        return 0;
    }
    if(mod) {
        val ++;
    }
    if(val > b || val < a) {
        cout << "No solution" << endl;
    }
    else{
        ll index = 0;
        for(ll i = 0 ; i < k ; i++) {
            ll add = arr[i];
            for(ll i = index; i < index + add ; i++) {
                cout << str[i];
            }
            cout << endl;
            index += add;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    string str;
    cin >> str;
    ll n = str.length();


    vector <ll> d1(n) , d2(n);
    for(ll i = 0 ; i < n ; i++) {
        d1[i] = 1;
        d2[i] = 0;
        while(i - d1[i] >= 0 && i + d1[i] < n && str[i - d1[i]] == str[i + d1[i]]) {
            d1[i] ++;
        }

        while(i - d2[i] - 1 >= 0 && i + d2[i] < n && str[i - d2[i] - 1] == str[i + d2[i]]) {
            d2[i] ++;
        }
    }

    string a = "" , b = "";
    ll index = 0 , mx = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(d1[i] > mx) {
            mx = d1[i];
            index = i;
        }
    }

    for(ll i = index - mx + 1 ; i < index + mx ; i++) {
        a += str[i];
    }

    index = 0 , mx = 0;
    for(ll i = 0 ; i < n ; i++) {
        if(d2[i] > mx) {
            mx = d2[i];
            index = i;
        }
    }

    for(ll i = index - mx ; i < index + mx ; i++) {
        b += str[i];
    }

    if(a.length() > b.length()) {
        cout << a << endl;
    }
    else{
        cout << b << endl;
    }

    return 0;
}

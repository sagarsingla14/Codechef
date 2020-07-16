#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool vowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

bool isdiff(char a , char b , char c) {
    if(a != b || b != c || c != a) {
        return true;
    }
    return false;
}

int main() {
    string str;
    cin >> str;
    ll n = str.length();
    vector <ll> index;
    for(ll i = 0 ; i < n - 2 ; i++) {
        if((!vowel(str[i]) && !vowel(str[i + 1]) && !vowel(str[i + 2])) && isdiff(str[i] , str[i + 1] , str[i + 2])) {
            index.push_back(i + 2);
            i = i + 1;
        }
    }
    if(index.size() == 0) {
        cout << str << endl;
    }
    else{
        ll ind = 0;
        for(ll i = 0 ; i < n ; i++) {
            if(i == index[ind] && ind < index.size()) {
                cout << " ";
                ind ++;
                i --;
            }
            else{
                cout << str[i];
            }
        }
        cout << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);


int main() {
    string str;
    getline(cin , str);

    stringstream s(str);

    string word;
    map <string , ll> mp;
    
    while(s >> word) {
        mp[word] ++;
    }

    for(auto i : mp) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    cout << str << endl;
}

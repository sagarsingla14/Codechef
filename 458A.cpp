#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 100000000000000

int main() {
    ll n;
    cin >> n;
    string str;
    map <string , string> mp;

    mp["purple"] = "Power";
    mp["green"] = "Time";
    mp["blue"] = "Space";
    mp["orange"] = "Soul";
    mp["red"] = "Reality";
    mp["yellow"] = "Mind";

    for(ll i = 0 ; i < n ; i++) {
        cin >> str;
        mp[str] = "";
    }

    cout << 6 - n << endl;
    for(auto i : mp) {
        if(i.second != "") {
            cout << i.second << endl;
        }
    }
    return 0;
}

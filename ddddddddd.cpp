#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007
#define INFI 1000000000000000000

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        string str;
        cin >> str;

        map <char , vector <vector <ll>>> mp;
        if(arr[0] == '0') {
            mp['0'].push_back(0);
        }
        else{
            mp['0'].push_back(1);
        }

        for(ll i = 1 ; i < n ; i++) {
            if(str[i] == '0') {
                if(mp['1'].size()) {
                    vector <ll> v = mp['1'];
                    ll con = v[v.size() - 1];
                    mp['1'].pop_back();

                }
            }
        }
    }
}

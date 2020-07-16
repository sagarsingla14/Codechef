#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define base 1000000007
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string name[n];
        ll num[n] ;
        string arriv[n] ;
        for(ll i = 0 ; i < n ; i++) {
            string s , a , d , l;
            cin >> s;
            ll nm;
            cin >> nm >> a >> d >> l;
            arriv[i] = a;
            name[i] = s;
            num[i] = nm;
        }

        ll arr[n] = {0};
        unordered_map <ll , ll> timenum;
        unordered_map <ll , string> numname;
        unordered_map <ll , string> numarr;
        for(ll i = 0; i < n ; i++) {
            numname[num[i]] = name[i];
            numarr[num[i]] = arriv[i];

            string str = arriv[i];
            string h = "";
            string m = "";
            string s = "";
            h = str[0] + str[1];
            s = str[6] + str[7];
            m = str[3] + str[4];
            stringstream geekh(s);
            stringstream geekm(s);
            stringstream geeks(s);
            ll hr , mn , ss;
            geekh >> hr;
            geekm >> mn;
            geeks >> ss;
            arr[i] = 3600 * hr + 60 * mn + ss;
            timenum[arr[i]] = num[i];
        }
        sort(arr, arr + n);
        cout << n << endl;
        for(ll i = 0 ; i < n ; i++) {
            // cout << name[i] << " " << num[i] << " " << 1 << endl;
            ll time = arr[i];
            cout << numname[time] -> second << " " << numarr[numname[time] -> second ] << " " << i + 1 << endl;
        }
    }
    return 0;
}

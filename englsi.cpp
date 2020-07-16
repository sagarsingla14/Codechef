#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        set <string> s;
        unordered_map  <string , ll> freq;
        for(ll i = 0 ; i < n ; i++) {
            string v;
            cin >> v;
            freq[v] ++;
            s.insert(v);
        }

        if(n == 1) {
            cout << 0 << endl;
            continue;
        }

        set <string> :: iterator itr;
        vector <string> str;

        for(itr = s.begin(); itr != s.end(); ++itr) {
            string ss = *itr;
            ll fre = freq[ss];
            for(ll i = 0 ; i < fre ; i++) {
                str.push_back(*itr);
            }
        }

        // for(ll i = 0; i < str.size(); i++) {
        //     cout << str[i] << endl;
        // }

        ll sum = 0;
        for(ll i = n - 1 ; i > 0 ; i--) {
            if(str[i] == str[i - 1]) {
                ll p = 0 , s = 0;

                for(ll j = 0 ; j < min(str[i].length() , str[i - 1].length()) ; j++) {
                    if(str[i][j] == str[i - 1][j]) {
                        p++;
                    }
                    else {
                        break;
                    }
                }

                ll s1 = str[i].length();
                ll s2 = str[i - 1].length();

                // cout << s1 << " " << s2 << endl;
                ll x = 0;

                for(ll j = min(s1 , s2) ; j > 0 ; j--) {
                    if(str[i][s1 - 1 - x] == str[i - 1][s2 - 1 - x]) {
                        s ++;
                    }
                    else {
                        break;
                    }
                    x ++;
                }

                // cout << p << " " << s << endl;
                ll mn = min(s , p);

                // cout << "min -> " << mn * mn << endl;
                sum += (mn * mn);
                str[i] = "-";
                str[i - 1] = "-";
                i--;
            }
        }

        // cout << "sum before - > " << sum << endl;

        // for(ll i = 0; i < str.size(); i++) {
        //     cout << str[i] << endl;
        // }

        vector <string> rem;
        for(ll i = 0 ; i < n ; i ++){
            if(str[i] != "-") {
                rem.push_back(str[i]);
            }
        }
        //
        // for(ll i = 0; i < rem.size(); i++) {
        //     cout << rem[i] << endl;
        // }

        if(rem.size() <= 1) {
            cout << sum << endl;
            continue;
        }

        ll rs = rem.size();
        // cout << " rem size - > " << rs << endl;
        ll sum1 = 0 , sum2 = 0;

        for(ll i = rs - 1 ; i > 0 ; i--) {
            // cout << str[i] << endl;
            ll p = 0 , s = 0;

            for(ll j = 0 ; j < min(rem[i].length() , rem[i - 1].length()) ; j++) {
                if(rem[i][j] == rem[i - 1][j]) {
                    p++;
                }
                else {
                    break;
                }
            }

            ll s1 = rem[i].length();
            ll s2 = rem[i - 1].length();

            // cout << s1 << " " << s2 << endl;
            ll x = 0;

            for(ll j = min(s1 , s2) ; j > 0 ; j--) {
                if(rem[i][s1 - 1 - x] == rem[i - 1][s2 - 1 - x]) {
                    s ++;
                }
                else {
                    break;
                }
                x ++;
            }

            // cout << p << " <- p  s ->  " << s << endl;
            ll mn = min(s , p);
            // cout << " mn -> " << mn << endl;
            // cout << "min -> " << mn * mn << endl;
            sum1 += (mn * mn);
            if(mn != 0) {
                i--;
            }
        }

        for(ll i = 0 ; i < rs - 1 ; i++) {
            // cout << str[i] << endl;
            ll p = 0 , s = 0;

            for(ll j = 0 ; j < min(rem[i].length() , rem[i + 1].length()) ; j++) {
                if(rem[i][j] == rem[i + 1][j]) {
                    p++;
                }
                else {
                    break;
                }
            }

            ll s1 = rem[i].length();
            ll s2 = rem[i + 1].length();

            // cout << s1 << " " << s2 << endl;
            ll x = 0;

            for(ll j = min(s1 , s2) ; j > 0 ; j--) {
                if(rem[i][s1 - 1 - x] == rem[i + 1][s2 - 1 - x]) {
                    s ++;
                }
                else {
                    break;
                }
                x ++;
            }

            // cout << p << " <- p  s ->  " << s << endl;
            ll mn = min(s , p);
            // cout << " mn -> " << mn << endl;
            // cout << "min -> " << mn * mn << endl;
            sum2 += (mn * mn);
            if(mn != 0) {
                i--;
            }
        }

        ll add = max(sum1 ,sum2);
        cout << sum + add << endl;

    }
    return 0;
}

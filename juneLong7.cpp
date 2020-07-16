#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll ans = 3;
        ll x , xx , y , yy , z , zz;
        cin >> x >> y >> z >> xx >> yy >> zz;
        vector <pair <ll , ll>> v;
        v.push_back({x , xx});
        v.push_back({y , yy});
        v.push_back({z , zz});

        vector <pair <ll , ll>> final;

        for(auto i : v) {
            if(i.first != i.second) {
                final.push_back({i.first , i.second});
            }
        }

        if(xx == yy && yy == zz) {
            ans = 2;
        }
        if(x == 0 && y == 0 && z == 0 && xx == 0 && yy == 0 && zz == 0) {
            // cout << 0 << endl;
            ans = min(ans , 0ll);
        }
        else if(xx == 0 && yy == 0 && zz == 0) {
            // cout << 1 << endl;
            ans = min(ans , 1ll);
        }
        else if(final.size() == 0) {
            ans = min(ans , 0ll);
            // cout << 0 << endl;
        }
        else if(final.size() == 1) {
            // cout << 1 << endl;
            ans = min(ans , 1ll);
        }
        else if(final.size() == 2) {
            ll a = final[0].first;
            ll b = final[1].first;
            ll p = final[0].second;
            ll q = final[1].second;

            ll d1 = -1;
            ll d2 = -1;

            ll m1 = -1;
            ll m2 = -1;

            if(a != 0) {
                d1 = p / a;
                m1 = (p % a);
            }
            if(b != 0) {
                d2 = q / b;
                m2 = (q % b);
            }

            ll diff1 = p - a;
            ll diff2 = q - b;

            if(m1 == 0 && m2 == 0 && m1 != -1 && m2 != -1) {
                if(diff1 == diff2) {
                    // cout << 1 << endl;
                    ans = min(ans , 1ll);

                }
                else if(d1 == d2) {
                    // cout << 1 << endl;
                    ans = min(ans , 1ll);
                }
                else {
                    // cout << 2 << endl;
                    ans = min(ans , 2ll);
                }
            }
            else {
                if(diff1 == diff2) {
                    ans = min(ans , 1ll);
                    // cout << 1 << endl;
                }
                else{
                    // cout << 2 << endl;
                    ans = min(ans , 2ll);
                }
            }
        }
        else{
            ll a = final[0].first;
            ll b = final[1].first;
            ll c = final[2].first;
            ll p = final[0].second;
            ll q = final[1].second;
            ll r = final[2].second;
            // cout << ans << endl;

            ll diff1 = p - a;
            ll diff2 = q - b;
            ll diff3 = r - c;

            ll d1 = -1;
            ll d2 = -1;
            ll d3 = -1;

            ll m1 = -1;
            ll m2 = -1;
            ll m3 = -1;

            if(a != 0) {
                d1 = p / a;
                m1 = (p % a);
            }
            if(b != 0) {
                d2 = q / b;
                m2 = (q % b);
            }
            if(c != 0) {
                d3 = r / c;
                m3 = (r % c);
            }

            if(d1 == d2 && d2 == d3 && m1 == 0 && m2 == 0 && m3 == 0) {
                ans = min(ans , 1ll);
            }
            else if(diff1 == diff2 && diff2 == diff3) {
                ans = min(ans , 1ll);
            }
            else if(diff1 == diff2) {
                ans = min(ans , 2ll);
            }
            else if(diff2 == diff3) {
                ans = min(ans , 2ll);
            }
            else if(diff1 == diff3) {
                ans = min(ans , 2ll);
            }
            else if(d1 == d2 && m1 == 0 && m2 == 0) {
                ans = min(ans , 2ll);
            }
            else if(d2 == d3 && m2 == 0 && m3 == 0) {
                ans = min(ans , 2ll);
            }
            else if(d1 == d3 && m1 == 0 && m3 == 0) {
                ans = min(ans , 2ll);
            }
            else {
                ans = min(ans , 3ll);
            }
        }
        if(ans <= 2) {
            cout << ans << endl;
            continue;
        }
        else {
            ll diffa = v[0].second - v[0].first;
            ll diffb = v[1].second - v[1].first;
            ll diffc = v[2].second - v[2].first;
            map <ll , ll> mp;

            mp[diffa] ++;
            mp[diffb] ++;
            mp[diffc] ++;

            if(mp[diffb - diffa]) {
                ans = 2;
            }
            else if(mp[diffc - diffa]) {
                ans = 2;
            }
            else if(mp[diffa - diffb]) {
                ans = 2;
            }
            else if(mp[diffc - diffb]) {
                ans = 2;
            }
            else if(mp[diffa - diffc]) {
                ans = 2;
            }
            else if(mp[diffb - diffc]) {
                ans = 2;
            }
        }
        if(ans == 3) {
            ll slope = 0;
            ll constant = 0;
            ll flag = 0;
            if(y - x != 0) {
                slope = (yy - xx) / (y - x);
                constant = xx - (x * slope);
                if((slope * x + constant == xx) && (slope * y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }

                else if((slope * x == xx) && (slope * y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }

                else if((x + constant == xx) && (slope * y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (slope * y == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (slope * y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (slope * y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (slope * y == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }

                else if((slope * x == xx) && (slope * y == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (slope * y == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                // cout << slope << " " << constant << " " << ans << endl;

            }
            if(z - x != 0) {
                slope = (zz - xx) / (z - x);
                constant = xx - (x * slope);

                if((slope * x + constant == xx) && (slope * y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }

                else if((slope * x == xx) && (slope * y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }

                else if((x + constant == xx) && (slope * y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (slope * y == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (slope * y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (slope * y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }

                else if((slope * x == xx) && (y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (slope * y == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }

                else if((slope * x == xx) && (slope * y == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (slope * y == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                // cout << slope << " " << constant << " " << ans << endl;
            }
            if(z - y != 0) {
                slope = (zz - yy) / (z - y);
                constant = yy - (y * slope);
                cout << slope << " " << constant << " " << ans << endl;

                if((slope * x + constant == xx) && (slope * y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }

                else if((slope * x == xx) && (slope * y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }

                else if((x + constant == xx) && (slope * y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (slope * y == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (slope * y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (slope * y == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (y + constant == yy) && (slope * z + constant == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (slope * y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x + constant == xx) && (y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (y + constant == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (slope * y == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }

                else if((slope * x == xx) && (slope * y == yy) && (z + constant == zz)) {
                    ans = 2;
                }
                else if((slope * x == xx) && (y + constant == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                else if((x + constant == xx) && (slope * y == yy) && (slope * z == zz)) {
                    ans = 2;
                }
                // cout << slope << " " << constant << " " << ans << endl;

            }
        }
        cout << ans << endl;
    }
    return 0;
}

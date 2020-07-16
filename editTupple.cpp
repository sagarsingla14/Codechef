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
            // *0
            ans = 2;
        }

        if(x == 0 && y == 0 && z == 0 && xx == 0 && yy == 0 && zz == 0) {
            ans = min(ans , 0ll);
        }
        else if(xx == 0 && yy == 0 && zz == 0) {
            ans = min(ans , 1ll);
        }

        if(final.size() == 0) {
            ans = min(ans , 0ll);
        }
        else if(final.size() == 1) {
            ans = min(ans , 1ll);
        }
        else if(final.size() == 2) {
            ll a = final[0].first;
            ll b = final[1].first;
            ll p = final[0].second;
            ll q = final[1].second;

            ll d1 = -10000000000000;
            ll d2 = -10000000000000;

            ll m1 = -10000000000000;
            ll m2 = -10000000000000;

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

            if(m1 == 0 && m2 == 0) {
                if(diff1 == diff2) {
                    ans = min(ans , 1ll);
                }
                else if(d1 == d2 && d1 != -10000000000000) {
                    ans = min(ans , 1ll);
                }
                else {
                    ans = min(ans , 2ll);
                }
            }
            else {
                if(diff1 == diff2) {
                    ans = min(ans , 1ll);
                }
                else{
                    ans = min(ans , 2ll);
                }
            }
        }
        else {

            ll da = (xx - x);
            ll db = (yy - y);
            ll dc = (zz - z);
            if(da + db == dc) {
                ans = 2;
            }
            else if(da + dc == db) {
                ans = 2;
            }
            else if(db + dc == da) {
                ans = 2;
            }

            ll a = final[0].first;
            ll b = final[1].first;
            ll c = final[2].first;
            ll p = final[0].second;
            ll q = final[1].second;
            ll r = final[2].second;

            ll diff1 = p - a;
            ll diff2 = q - b;
            ll diff3 = r - c;

            ll d1 = -10000000000000;
            ll d2 = -10000000000000;
            ll d3 = -10000000000000;

            ll m1 = -10000000000000;
            ll m2 = -10000000000000;
            ll m3 = -10000000000000;

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

            if(d1 == d2 && d2 == d3 && m1 == 0 && m2 == 0 && m3 == 0 && d1 != -10000000000000) {
                ans = min(ans , 1ll);
            }
            else if(d1 == d2 && d2 == d3 && m1 == m2 && m2 == m3 && m1 != 0 && d1 != -10000000000000) {
                ans = min(ans , 2ll);
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

            ll slope = 0;
            ll constant = 0;
            ll flag = 0;
            if(y - x != 0) {
                slope = (yy - xx) / (y - x);
                constant = yy - (y * slope);
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
            }
            if(z - x != 0) {
                slope = (zz - xx) / (z - x);
                constant = zz - (z * slope);

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
            }
            if(z - y != 0) {
                slope = (zz - yy) / (z - y);
                constant = zz - (z * slope);

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
            }
        }
        cout << ans << endl;
    }
    return 0;
}

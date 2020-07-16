#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n , m;
    cin >> n >> m;
    vector <ll> v[m];
    vector <ll> mat[n];

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < n ; j++){
            mat[i].push_back(0);
        }
    }

    ll cells[m] = {0};
    for(ll i = 0 ; i < m ; i++) {
        ll x1, y1, x2, y2, val;
        cin  >> x1 >> y1 >> x2 >> y2 >> val;
        ll xx = abs(x2 - x1) + 1;
        ll yy = abs(y2 - y1) + 1;
        cells[i] = xx * yy;
        v[i].push_back(x1);
        v[i].push_back(y1);
        v[i].push_back(x2);
        v[i].push_back(y2);
        v[i].push_back(val);
        v[i].push_back(0);
    }

    sort(cells , cells + m);

    // for(ll i = 0 ; i < m ; i++) {
    //     cout << cells[i] << " ";
    // }
    // cout << endl;

    for(ll i = 0 ; i < m ; i++) {
        for(ll j = 0 ; j < m ; j++) {
            if(v[j][5] == 0) {
                ll xx = abs(v[j][2] - v[j][0]) + 1;
                ll yy = abs(v[j][3] - v[j][1]) + 1;
                // cout << xx * yy << endl;
                if(xx * yy == cells[i]) {
                    v[j][5] = 1;
                    ll x1 = v[j][0];
                    ll x2 = v[j][2];
                    ll y1 = v[j][1];
                    ll y2 = v[j][3];
                    ll count = 0;
                    for(ll r = x1 - 1 ; r <= x2 - 1 ; r++) {
                        for(ll c = y1 - 1; c <= y2 - 1 ; c++) {
                            if(mat[r][c] == 0) {
                                count ++;
                            }
                        }
                    }
                    if(count == 0) {
                        break;
                    }
                    ll putVal = v[j][4] / count;
                    ll placeone = 0;
                    if(putVal == 0) {
                        placeone = v[j][4];
                    }
                    count = 0;
                    // cout << putVal << endl;
                    if(putVal) {
                        for(ll r = x1  - 1; r <= x2 - 1 ; r++) {
                            for(ll c = y1 -1 ; c <= y2 - 1 ; c++) {
                                if(mat[r][c] == 0) {
                                    mat[r][c] = putVal;
                                }
                            }
                        }
                    }
                    else{
                        for(ll r = x1  - 1; r <= x2 - 1 ; r++) {
                            for(ll c = y1 -1 ; c <= y2 - 1 ; c++) {
                                if(mat[r][c] == 0 && count < placeone) {
                                    mat[r][c] = 1;
                                    count++;
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
    }

    for(ll i = 0 ; i < n ; i++) {
        for(ll j = 0 ; j < n ; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll x = 0 , y = 0;
ll fx = 0 , fy = 0;
ll a , b;
ll n = 0;
string str;
ll ok = 0;
ll quadrant = 0;

ll findQuadrant() {
    if(a >= 0 && b >= 0) {
        return 1;
    }
    else if(a < 0 && b >= 0) {
        return 2;
    }
    else if(a <= 0 && b <= 0) {
        return 3;
    }
    else {
        return 4;
    }
}

void print() {
    if(ok) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

void checkInpath() {
    ll curX = x , curY = y;
    for(ll i = 0 ; i < n ; i++) {
        if(curX == a && curY == b) {
            ok = 1;
        }
        if(str[i] == 'U') {
            curY ++;
        }
        if(str[i] == 'D') {
            curY --;
        }
        if(str[i] == 'R') {
            curX ++;
        }
        if(str[i] == 'L') {
            curX --;
        }
        if(curX == a && curY == b) {
            ok = 1;
        }
    }
    fx = curX , fy = curY;
}

pair <ll , ll> finalCheck(ll xx , ll yy) {
    ll curX = xx , curY = yy;
    for(ll i = 0 ; i < n ; i++) {
        if(curX == a && curY == b) {
            ok = 1;
        }
        if(str[i] == 'U') {
            curY ++;
        }
        if(str[i] == 'D') {
            curY --;
        }
        if(str[i] == 'R') {
            curX ++;
        }
        if(str[i] == 'L') {
            curX --;
        }
        if(curX == a && curY == b) {
            ok = 1;
        }
    }
    pair <ll , ll> p = {curX , curY};
    return p;
}

bool check(ll mul) {
    ll curX = fx * mul;
    ll curY = fy * mul;

    pair <ll , ll> p = finalCheck(curX , curY);

    // cout << "mul curx cury a b quad " << mul << " " << curX << " " << curY << " " << a << " " << b << " " << ok << endl;

    if(quadrant == 1) {
        if(a != 0 && b != 0) {
            if(curX < a && curY < b) {
                if(p.first > a && p.second > a) {
                    return false;
                }
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if(a == 0) {
                if(curY < b) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else{
                if(curX < a) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    else if(quadrant == 2) {
        if(a != 0 && b != 0) {
            if(curX > a && curY < b) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if(a == 0) {
                if(curY < b) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else{
                // cout << "hoho " << endl;
                if(curX > a) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    else if(quadrant == 3) {
        if(a != 0 && b != 0) {
            if(curX > a && curY > b) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if(a == 0) {
                if(curY > b) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else{
                if(curX > a) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
    else {
        if(a != 0 && b != 0) {
            if(curX < a && curY > b) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if(a == 0) {
                if(curY > b) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else{
                if(curX < a) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
    }
}

void solve() {
    ll f = 1 , l = 1e9;
    ll point = 0;

    while(f <= l) {
        ll mid = (f + l) / 2;
        // cout << "Mid " << mid << endl;

        if(check(mid)) {
            f = mid + 1;
            point = mid;
        }
        else {
            l = mid - 1;
        }
    }

    // cout << "POINt "<< point << endl;
    //
    // cout << fx << " " << fy << endl;

    x = fx * point;
    y = fy * point;

    // cout << x << " " << y << endl;0 0

    str += str;
    n = str.length();
    checkInpath();
    // cout << fx << " " << fy << endl;
    //
    // x = fx * (point + 1);
    // y = fy * (point + 1);
    // checkInpath();
    // cout << fx << " " << fy << endl;
}

int main() {
    cin >> a >> b;
    cin >> str;

    n = str.length();

    checkInpath();
    // cout << fx << " " << fy << endl;

    quadrant = findQuadrant();
    // cout << quadrant << endl;
    solve();

    print();

    return 0;
}

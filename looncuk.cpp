#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll m1 = 0 , y1 = 0 , m2 = 0 , y2 = 0 , count = 0, left = 0 , right = 0;
void calca();
void calcb();
void setval();


void setval() {
    if(m2 < 2) {
        y2 --;
    }
    if(m1 > 2) {
        y1 ++;
        m1 = 2 , m2 = 2;;
    }
}

void  calcb() {
    for(ll i = y1 ; i <= y2; i++) {
        ll op = (2*(i/100))+((i%100)-1)+((i%100)-1)/4 + ((i/100)/4);
        ll p = (32 - op) % 7;
        ll q = (33 - op) % 7;
        if(q == 0) {
            count ++;
            continue;
        }
        else if(p == 0) {
            if(!((i % 4 == 0 && i % 100 != 0) || i % 400==0 )) {
                count ++;
            }
        }
    }
    cout << count << endl;
}

void calca() {
    unordered_map <ll,ll> check;
    ll x = left * 100 + 99;
    ll a = 0;
    ll y = right * 100;
    ll b = 0;

    for(ll i = y ; i <= y2 ; i++) {
        ll op = (2*(i/100))+((i%100)-1)+((i%100)-1)/4 + ((i/100)/4);
        ll p = (32 - op ) % 7;
        ll q = (33 - op ) % 7;
        if(q==0) {
            b++;
            continue;
        }
        else if(p == 0) {
            if(!((i%4==0&&i%100!=0) || i%400==0)) {
                b++;
            }
        }
    }

    for(ll i = y1 ; i <= x ; i++) {
        ll op = (2*(i/100))+((i%100)-1)+((i%100)-1)/4 + ((i/100)/4);
        ll q = (33 - op) % 7;
        ll p = (32 - op) % 7;

        if(q == 0) {
            a++;
            continue;
        }
        else if(p==0) {
            if(!((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)) {
                a++;
            }
        }
    }

    ll ans = a + b;
    ll z = left + 1;
    ll aaa = z % 4;
    ll zz = right - 1;
    ll tot = zz - z + 1;
    ll jod = tot / 4;
    ll c = 0;
    c += (25*jod);
    c += (24*jod);
    c += (26*jod);
    c += (26*jod);
    check[0] = 25;
    check[1] = 24;
    check[2] = 26;
    check[3] = 26;
    for(ll i = aaa ; i < aaa + (tot % 4) ; i++) {
        c += check[i % 4];
    }
    cout << ans + c << endl;
}



int main () {
    ll t;
    cin >> t;
    while(t--) {
        cin >> m1 >> y1 >> m2 >> y2;
        setval();
        count = 0;
        left = y1 / 100;
        right = y2 / 100;
        if(right - left > 1) {
            calca();
        }
        else{
            calcb();
        }
    }
}

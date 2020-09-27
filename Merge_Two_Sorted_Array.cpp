#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {

    ll n , m;
    cin >> n >> m;
    ll a[n] , b[m];


    for(ll i = 0 ; i < n ; i++) cin >> a[i];
    for(ll i = 0 ; i < m ; i++) cin >> b[i];

    int gap = ((m + n) >> 1) + ((m + n) % 2);
    while(gap) {
        // first only
        int left = 0 , right = gap;
        while(right < n) {
            if(a[left] > a[right]) {
                swap(a[left] , a[right]);
            }
            left ++ , right ++;
        }

        // Second Only
        right = 0;
        while(left < n && right < m) {
            if(a[left] > b[right]) {
                swap(a[left] , b[right]);
            }
            left ++ , right ++;
        }

        // Third Only
        left = 0 , right = gap;
        while(right < m) {
            if(b[left] > b[right]) {
                swap(b[left] , b[right]);
            }
            left ++ , right ++;
        }

        if(gap == 1) {
            break;
        }
        gap = gap / 2 + gap % 2;
    }


    for(int i = 0 ; i < n ; i++) {
        cout << a[i] << " " ;
    }
    for(int i = 0 ; i < m ; i++) {
        cout << b[i] << " " ;
    }
    cout << endl;

    return 0;
}

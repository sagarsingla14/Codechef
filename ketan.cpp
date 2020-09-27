#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int arr[100001];

void arrayPass(ll a[] , ll n) {
    for(ll i = 0 ; i < n ; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}



// idhr &lgana zruri h , map , set , vector jo function me ayega to & lgana pdega, vrna sari values 0 hojygi vector mai
void vecPass(vector <ll> &v , ll n) {
    for(ll i = 0 ; i < n ; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // ya phir
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        // to initalise ever element of global array - arr by 0; , 0 ke alawa kch or krna h to loop chla ke krna pdega
        memset(arr , 0 , sizeof(arr));

        ll n;
        cin >> n;
        ll a[n] = {0}; // array a initalized to 0;
        arrayPass(a , n);

        // vector, map , set ko ese pass krte h
        vector <ll> v(n , 0); // n size ka vector in which every element is 0.. yaaha pe 0 ke alwa kch bhi ho skta h..
        vecPass(v , n);

    }
    return 0;
}

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll n = 10;
    // Bounds on Vector.
    vector <ll> v(n);
    for(ll i = 0 ; i < n ; i++) {
        v[i] = 5 + i / 2;
    }

    sort(v.begin() , v.end());

    for(ll i = 0 ; i < n ; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // index of value to be seached in vector and array.
    ll val = 7;

    // Lower Bound returns the index of First occurence of value.
    // Upper Bound returns the (index of last occurence of value) + 1.
    auto lowans = lower_bound(v.begin() , v.end() , val) - v.begin();
    auto upans = upper_bound(v.begin() , v.end() , val) - v.begin();
    cout << "lower Bound -> " << lowans << endl;
    cout << "Upper Bound -> " << upans << endl;


    // Bound on Array.
    // Similarly on an array .. on differnce is just syntax to compute bounds.
    ll arr[n] = {0};
    for(ll i = 0; i < n ; i ++){
        arr[i] = v[i];
    }

    upans = upper_bound(arr , arr + n , val) - arr;
    lowans = lower_bound(arr , arr + n , val) - arr;

    cout << "Upper Bound -> " << upans << endl;
    cout << "lower Bound -> " << lowans << endl;

    // Best Thing is this is also known as *Binary Search Algorithm*.
    // Time Complexity to Compute Lower and Upper Bound is O(Log(n)) :-P
    // now you need not to write long code Binary Search


    // to copy an array into a vector v;
    vector <ll> copy(arr , arr + 7);
    for(ll i = 0 ; i < copy.size() ; i++) {
        cout << copy[i] << " ";
    }
    cout << endl;

    // Challenge :
    // think what would happen if we Search for the elements that are not present in the array or vector ?
    // Run it By changing Value of *Val* variable

    return 0;
}

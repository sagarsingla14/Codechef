#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;

    ll arr[n];
    for(ll i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    ll gap = n / 2 + n % 2;

    while(gap) {
        int left = 0 , right = gap;
        while(right < n) {
            if(arr[left] > arr[right]) {
                swap(arr[left] , arr[right]);
            }
            left ++ , right ++;
        }
        if(gap == 1) {
            break;
        }
        gap = gap / 2 + gap % 2;
    }

    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

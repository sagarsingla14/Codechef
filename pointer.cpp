#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int *arr(ll n) {
    int *st = new int[n];
    st[0] = 21;
    return st;
}
int main(){
    int *p = arr(5);
    cout << *p << endl;
    for(ll i = 0 ; i < 10 ; i++ ){
        cout << p[i] << endl;
    }
    cout << p << endl;
    cout << &p << endl;

}

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

string str[10];
ll n;

bool comp(string a , string b) {
    return a > b;
}

bool comp1(string a , string b) {
    return a < b;
}

bool sortBylengthasc(string a , string b) {
    return a.length() < b.length();
}

bool sortBylengthdsc(string a , string b) {
    return a.length() > b.length();
}

void print() {
    for(ll i = 0 ; i < n ; i++) {
        cout << str[i] << " ";
    }
    cout << endl;
}

int main() {
    fast_io
    cin >> n;
    for(ll i = 0 ; i < n ; i++) {
        cin >> str[i];
    }

    // ARRAY OF STRINGS SORTED BY

    // LEXO. SMALLEST TO LARGEST WITHOUT COMPARATOR FUNCTION
    sort(str , str + n);
    print();

    // LEXO. LARGEST TO SMALLEST
    sort(str , str + n , comp);
    print();

    // LEXO. LARGEST TO SMALLEST USING COMPARATOR FUNCTION
    sort(str , str + n , comp1);
    print();

    //  SORTED BY LENGTH IN ASCENDING ORDER
    sort(str , str + n , sortBylengthasc);
    print();

    // SORTED BY LENGTH IN DESCENDING ORDER
    sort(str , str + n , sortBylengthdsc);
    print();

    return 0;
}

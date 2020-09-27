#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100] = {0};
vector <vector <int>> ans;
void print() {
    for(auto i : ans) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

void solve(int index , vector <int> &v) {
    if(index == n) {
        ans.push_back(v);
        return;
    }
    
    ans.push_back(v);
    for(int i = index ; i < n ; i++) {
        v.push_back(arr[i]);
        solve(i + 1 , v);
        v.pop_back();
    }
}

int main() {
    cin >> n;
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    vector <int> v;
    solve(0 , v);
    print();
}

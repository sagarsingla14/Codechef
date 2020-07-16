#include <bits/stdc++.h>

using namespace std;


int main() {
    int n; cin >> n;
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        prefix[i + 1] = prefix[i] + x;
    }

    int begin = 0, end = 0;
    long long ans = 0;
    set <long long> s = {0 , 5 , 10};

    for(auto i : prefix) {
        cout << i << " ";
    }
    cout << endl << endl;

    while(begin < n) {
        while(end < n && !s.count(prefix[end + 1])) {
            ++end;
            s.insert(prefix[end]);
        }
        ans += end - begin;

        cout << "begin end " << begin << " " << end << endl;
        cout << "before ";
        for(auto itr : s) {
            cout << itr << " ";
        }
        cout << endl;
        s.erase(prefix[begin]);
        cout << "after ";
        for(auto itr : s) {
            cout << itr << " ";
        }
        cout << endl << endl;
        ++begin;
    }
    cout << ans << endl;
}

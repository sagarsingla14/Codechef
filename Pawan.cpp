#include <bits/stdc++.h>
using namespace std;
multiset<pair<string , int > > mul;

int main(){
    string ss;
    int k;
    cin >> ss >> k;
    for(int i = 0 ; i < ss.size(); i++){
        string temp;
        temp += ss[i];
        mul.insert({temp , i});
    }

    long long n = ss.size();
    if(2 * k > n * (n + 1)) {
        cout << "No such line." << endl;
    }
    else {
        pair <string ,int> p , ans;
        while(k--){
            ans = p = *mul.begin();
            mul.erase(mul.begin());
            if(p.second + 1 < n){
                p.first += ss[p.second + 1];
                p.second += 1;
                mul.insert(p);
            }
        }
        cout << ans.first << endl;
    }
    return 0;
}

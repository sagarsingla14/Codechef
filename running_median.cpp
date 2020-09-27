#include <bits/stdc++.h>
using namespace std;

int n , med;
int t;
priority_queue <int> a;
priority_queue <int , vector <int> , greater <int>> b;

int main() {
    cin >> t;
    for(int i = 0 ; i < t ; i++) {
        cin >> n;
        if(i == 0) {
            a.push(n);
            cout << n << endl;
            med = n;
        }


        else{
            if(a.size() > b.size()) {
                if(n < med) {
                    b.push(a.top());
                    a.pop();
                    a.push(n);
                }
                else {
                    b.push(n);
                }
                med = (a.top() + b.top()) / 2;
            }
            else if(a.size() == b.size()) {
                if(n < med) {
                    a.push(n);
                    med = a.top();
                }
                else {
                    b.push(n);
                    med = b.top();
                }
            }
            else if(b.size() > a.size()){
                if(n > med) {
                    a.push(b.top());
                    b.pop();
                    b.push(n);
                }
                else {
                    a.push(n);
                }
                med = (a.top() + b.top()) / 2;
            }
            cout << med << endl;
        }
    }
	return 0;
}

class Solution {
public:
    #define ll int
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack <ll> s;
        ll ans = 0;

        for(ll i = 0 ; i < n ; i++) {
            if(s.empty()) {
                s.push(i);
            }
            else{
                if(arr[i] >= arr[s.top()]) {
                    s.push(i);
                }
                else{
                    while(arr[i] < arr[s.top()]) {
                        ll index = s.top();
                        s.pop();
                        if(s.empty()) {
                            ans = max(ans , arr[index] * i);
                            break;
                        }
                        else {
                            ans = max(ans , arr[index] * (i - s.top() - 1));
                        }
                    }
                    s.push(i);
                }
            }
        }

        while(!s.empty()) {
            ll index = s.top();
            s.pop();
            if(s.empty()) {
                ans = max(ans , arr[index] * n);
            }
            else {
                ans = max(ans , arr[index] * (n - s.top() - 1));
            }
        }
        return ans;
    }
};

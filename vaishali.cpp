#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mod 1e9 + 7
using namespace std;

int findFirst(vector<int>& nums, int start, int end, int target){
    int first = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(nums[mid] == target){
            first = mid;
            end = mid - 1;
        } else if(nums[mid] < target){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return first;
}

int findLast(vector<int>& nums, int start, int end, int target){
    int last = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(nums[mid] == target){
            last = mid;
            start = mid + 1;
        } else if(nums[mid] < target){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return last;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int target;
    cin >> target;
    int first = findFirst(nums, 0, n - 1, target);
    int last = findLast(nums, 0, n - 1, target);

    int ans = last - first + 1;
    cout << ans << "\n";
    return 0;
}

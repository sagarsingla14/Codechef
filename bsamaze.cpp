#include<bits/stdc++.h>
using namespace std;
int frequency(vector<int> arr, int n, int key){
    int f=0;
    int l=0, r=n;
    while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]>=key) r=mid;
        else if(arr[mid]<key) l=mid+1;
    }
    int lower_bound=l;
    l=0, r=n;
    while(l<r){
        int mid=l+(r-l)/2;
        if(arr[mid]>key) r=mid;
        else if(arr[mid]<=key) l=mid+1;
    }
    int upper_bound=l;

    return upper_bound-lower_bound;
}

int main() {
	int n;
	cin>>n;
	vector<int> ar;
	for(int i=0;i<n;i++) {
        int x;
        cin>>x;
		ar.push_back(x);
    }
	int q;
	cin>>q;
	while(q--) {
		int k;
		cin>>k;
		cout<<frequency(ar, n, k)<<endl;;
	}
    return 0;
}

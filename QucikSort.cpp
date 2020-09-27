#include <bits/stdc++.h>
using namespace std;

int findPivot(int arr[] , int l , int r) {
    int pivot = arr[r];
    int start = l - 1;

    for(int i = l ; i <= r - 1 ; i++) {
        if(arr[i] < pivot) {
            start ++;
            swap(arr[start] , arr[i]);
        }
    }

    swap(arr[start + 1] , arr[r]);
    return start + 1;
}

void quickSort(int arr[] , int l , int r) {
    if(r > l) {
        int pivot = findPivot(arr , l , r);
        quickSort(arr , l , pivot - 1);
        quickSort(arr , pivot + 1 , r);
    }
    return;
}

int main() {
    int n;
    cin >> n;

    int arr[n] = {0};
    for(int i = 0 ; i < n ; i ++) {
        cin >> arr[i];
    }

    quickSort(arr , 0 , n - 1);

    cout << "Sorted Array ";
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

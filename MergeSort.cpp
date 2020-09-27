#include <bits/stdc++.h>
using namespace std;

void merge(int arr[] , int l , int mid , int r , int n) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int left[n1] = {0};
    int right[n2] = {0};

    for(int i = 0 ; i < n1 ; i++) {
        left[i] = arr[l + i];
    }
    for(int i = 0 ; i < n2 ; i++) {
        right[i] = arr[mid + i + 1];
    }

    int i = 0 , j = 0 , k = l;
    while(i < n1 && j < n2) {
        if(left[i] > right[j]) {
            arr[k] = right[j];
            j ++;
            k ++;
        }
        else{
            arr[k] = left[i];
            i ++;
            k ++;
        }
    }

    while(i < n1) {
        arr[k] = left[i];
        k ++;
        i ++;
    }
    while(j < n2) {
        arr[k] = right[j];
        k ++;
        j ++;
    }
    return ;
}

void mergeSort(int arr[] , int l , int r , int n) {
    if(l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr , l , mid , n);
        mergeSort(arr , mid + 1 , r , n);
        merge(arr , l , mid , r , n);
    }
    return ;
}

int main() {
    int n;
    cin >> n;

    int arr[n] = {0};
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
    }

    mergeSort(arr , 0 , n - 1 , n);

    cout << "Sorted Array ";
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

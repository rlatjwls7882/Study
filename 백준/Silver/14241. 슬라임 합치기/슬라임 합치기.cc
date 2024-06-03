#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int sum=0, mul=arr[0];
    for(int i=1;i<n;i++) {
        sum += mul*arr[i];
        mul+=arr[i];
    }
    cout << sum;
}
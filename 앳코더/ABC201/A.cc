#include<bits/stdc++.h>

using namespace std;

int main(void) {
    int arr[3];
    for(int i=0;i<3;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+3);

    if(arr[2]-arr[1]==arr[1]-arr[0]) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}
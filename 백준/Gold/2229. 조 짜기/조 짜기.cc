#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int arr[N+1];
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
    }

    int sum[N+1] = {0, }, minVal[N+1], maxVal[N+1];
    for(int i=1;i<=N;i++) {
        int tmpMax = arr[i];
        int tmpMin = arr[i];
        for(int j=i-1;j>0;j--) {
            tmpMax = max(tmpMax, arr[j]);
            tmpMin = min(tmpMin, arr[j]);
            if(sum[i]<sum[j-1]+tmpMax-tmpMin) {
                maxVal[i]=tmpMax;
                minVal[i]=tmpMin;
                sum[i] = sum[j-1] + tmpMax-tmpMin;
            }
        }
    }
    cout << sum[N];
}
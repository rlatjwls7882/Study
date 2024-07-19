#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    int arr[N];
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }

    int select[N][2];
    int cnt=0, sum=0;
    for(int i=0;i<N;i++) {
        sum += arr[i];
        cnt++;
        if(sum>=K) {
            select[i][0]=sum-K;
            select[i][1]=cnt;
            while(sum>=K) {
                sum -= arr[i+1-cnt--];
            }
        } else {
            select[i][0]=select[i][1]=0;
        }
    }

    long long maxEnergy=select[0][0];
    long long dp[N]; dp[0]=select[0][0];
    for(int i=1;i<N;i++) {
        dp[i]=dp[i-1];
        if(i-select[i][1]>=0) dp[i] = max(dp[i], dp[i-select[i][1]]+select[i][0]);
        maxEnergy = max(maxEnergy, dp[i]);
    }
    cout << maxEnergy;
}
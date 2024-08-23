#include <bits/stdc++.h>
using namespace std;

int n;
int arr[40];
vector<int> num1, num2;
long long cnt1[4000001] = {0, }, cnt2[4000001] = {0, };

void dfs1(int start, int sum, int depth) {
    if(++cnt1[sum+2000000]==1) num1.push_back(sum);
    for(int i=start;i<n/2;i++) {
        dfs1(i+1, sum+arr[i], depth+1);
    }
}

void dfs2(int start, int sum, int depth) {
    cnt2[sum+2000000]++;
    for(int i=start;i<n;i++) {
        dfs2(i+1, sum+arr[i], depth+1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int s; cin >> n >> s;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    dfs1(0, 0, 0);
    dfs2(n/2, 0, 0);

    long long cnt = 0;
    if(s==0) cnt--;
    for(int curNum:num1) {
        cnt += cnt1[curNum+2000000] * cnt2[s-curNum+2000000];
    }
    cout << cnt;
}
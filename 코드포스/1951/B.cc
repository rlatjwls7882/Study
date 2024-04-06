#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio; cin.tie(); cout.tie();
    int t; cin >> t;

    while(t-->0) {
        int n, k; cin >> n >> k;

        int a[n];
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }

        // 1번 위치로
        int maxCnt=0;
        for(int i=1;i<n;i++) {
            if(a[k-1] > a[i] || k-1==i && a[k-1]>a[0]) {
                maxCnt++;
            } else {
                break;
            }
        }

        // i번 위치로
        for(int i=1;i<n;i++) {
            if(i>k-1 && a[i]>a[k-1] || a[i-1]>a[k-1]) {
                break;
            }

            int cnt=1;
            for(int j=i+1;j<n;j++) {
                if(a[k-1]>a[j] || k-1==j && a[k-1]>a[i]) {
                    cnt++;
                } else {
                    break;
                }
            }
            maxCnt = max(cnt, maxCnt);
        }
        cout << maxCnt << endl;
    }
}
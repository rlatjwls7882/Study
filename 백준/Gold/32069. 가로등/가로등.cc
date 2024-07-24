#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long L; int N, K; cin >> L >> N >> K;
    long long A[N];
    for(int i=0;i<N;i++) {
        cin >> A[i];
    }

    while(K>0) {
        for(int i=0;K>0;i++) {
            if(N==1) {
                if(i==0) {
                    cout << "0\n";
                    K--;
                } else {
                    if(A[0]-i>=0) {
                        cout << i << '\n';
                        K--;
                    }
                    if(K>0 && A[0]+i<=L) {
                        cout << i << '\n';
                        K--;
                    }
                }
            } else {
                for(int j=0;j<N && K>0;j++) {
                    if(i==0) {
                        cout << "0\n";
                        K--;
                    } else if(j==0) {
                        if(A[j]-i>=0) {
                            cout << i << '\n';
                            K--;
                        }
                    } else {
                        if(j==N-1) {
                            if(A[j]+i<=L) {
                                cout << i << '\n';
                                K--;
                            }
                        }
                        if((A[j]-A[j-1]+1)/2>=i) {
                            cout << i << '\n';
                            K--;
                            if(K>0 && i*2<=A[j]-A[j-1]) {
                                cout << i << '\n';
                                K--;
                            }
                        }
                    }
                }
            }
        }
    }
}
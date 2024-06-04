#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;

    int _size = 100000;
    bool notSosu[_size] = {false, };
    for(int i=2;i*i<_size;i++) {
        if(!notSosu[i]) {
            for(int j=i*i;j<_size;j+=i) {
                notSosu[j]=true;
            }
        }
    }
    vector<int> sosu;
    for(int i=2;i<_size;i++) {
        if(!notSosu[i]) {
            sosu.push_back(i);
        }
    }

    if(N<=1) {
        cout << 0;
        return 0;
    }
    for(int i=0;i<sosu.size();i++) {
        if(N%sosu[i]==0) {
            if(N==sosu[i]) cout << N-1;
            else cout << N-N/sosu[i];
            return 0;
        }
    }
    cout << N-1;
}
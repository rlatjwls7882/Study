#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N, R; cin >> N >> R;
    R = min(R, N-R);
    long long div=R;

    long long mul=1;
    for(int i=0;i<R;i++) {
        mul*=(N-i);
        while(div>1 && mul%div==0) {
            mul/=div;
            div--;
        }
        mul%=MOD;
    }
    cout << mul;
}
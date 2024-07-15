#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string L, R; cin >> L >> R;

    int cnt=0;
    if(L.length()==R.length()) {
        bool alwaysSmall=false;
        for(int i=0;i<L.length();i++) {
            if(!alwaysSmall && L[i]=='8' && R[i]=='8') cnt++;
            else if(L[i]!=R[i] && L[i]<R[i]) alwaysSmall=true;
        }
    }
    cout << cnt;
}
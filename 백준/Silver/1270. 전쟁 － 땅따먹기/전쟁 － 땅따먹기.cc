#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while(n-->0) {
        int T; cin >> T;
        map<long long, int> m;
        for(int i=0;i<T;i++) {
            long long cnt; cin >> cnt;
            m[cnt]++;
        }
        
        bool chk=false;
        for(auto p:m) {
            if(p.second>T/2) {
                cout << p.first << '\n';
                chk=true;
                break;
            }
        }
        if(!chk) cout << "SYJKGW\n";
    }
}
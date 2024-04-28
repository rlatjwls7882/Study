#include<bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    
    cout << "YES\n";
    if(s[0]=='.') {
        cout << s.substr(1, s.length()-1) << " 1";
        for(int i=0;i<s.length()-1;i++) {
            cout << 0;
        }
    } else {
        cout << s.substr(2, s.length()-2) << " 1";
        for(int i=0;i<s.length()-2;i++) {
            cout << 0;
        }
    }
}
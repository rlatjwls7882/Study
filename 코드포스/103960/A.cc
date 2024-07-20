#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    string s; cin >> s;
    int sum=0, cur=1;
    for(int i=0;i<s.length();i++) {
        if(s[i]=='a' && s[i+1]=='a') {
            cur++;
        } else {
            if(cur!=1) sum += cur;
            cur=1;
        }
    }
    cout << sum;
}
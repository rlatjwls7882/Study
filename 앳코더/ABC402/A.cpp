#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    for(char ch:s) {
        if(ch<='Z') cout << ch;
    }
}

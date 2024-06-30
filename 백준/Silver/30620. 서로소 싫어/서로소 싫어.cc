#include<bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long x, y; cin >> x >> y;

    cout << "2\n";
    if(x==y) {
        cout << x << "\n" << -x;
    } else {
        cout << x*(y-1) << '\n' << -(x-1)*y;
    }
}
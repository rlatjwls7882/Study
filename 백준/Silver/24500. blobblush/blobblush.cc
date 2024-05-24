#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow(ll a, int b) {
    ll sum=1;
    while(b-->0) {
        sum*=a;
    }
    return sum;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll N; cin >> N;
    bitset<64> bin = bitset<64>(N);

    int size=64;
    for(int i=63;i>=0;i--) {
        if(!bin[i]) size=i;
        else break;
    }

    ll sum=0;
    for(int i=0;i<size;i++) {
        if(!bin[i]) {
            sum += pow((ll)2, i);
        }
    }

    if(sum!=0) {
        cout << "2\n" << min(sum, N) << '\n' << max(sum, N);
    } else {
        cout << "1" << '\n' << N;
    }
}
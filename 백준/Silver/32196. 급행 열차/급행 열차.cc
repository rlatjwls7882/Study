#include <bits/stdc++.h>
using namespace std;

long long N, M, K, X, Y;

struct Node {
    long long A, B;
    bool operator<(const Node a) const {
        return this->A*X - this->B*Y > a.A*X - a.B*Y;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K >> X >> Y;
    priority_queue<Node> pq;
    vector<pair<long long, long long>> AB;
    for(int i=0;i<N;i++) {
        long long A, B; cin >> A >> B;
        pq.push({A, B});
    }

    long long A=K, B=K;
    while(M-->0) {
        A += pq.top().A;
        B -= pq.top().B;
        pq.pop();
    }
    cout << A*X+B*Y;
}
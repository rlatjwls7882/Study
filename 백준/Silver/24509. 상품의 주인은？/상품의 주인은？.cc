#include<bits/stdc++.h>
using namespace std;

struct stu {
    int X, A, B, C, D;
    stu(int X, int A, int B, int C, int D) {
        this->X=X;
        this->A=A;
        this->B=B;
        this->C=C;
        this->D=D;
    }
};

bool comp1(stu a, stu b) {
    if(a.A==b.A) return a.X>b.X;
    return a.A<b.A;
}

bool comp2(stu a, stu b) {
    if(a.B==b.B) return a.X>b.X;
    return a.B<b.B;
}

bool comp3(stu a, stu b) {
    if(a.C==b.C) return a.X>b.X;
    return a.C<b.C;
}

bool comp4(stu a, stu b) {
    if(a.D==b.D) return a.X>b.X;
    return a.D<b.D;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;

    vector<stu> v;
    for(int i=0;i<N;i++) {
        int X, A, B, C, D; cin >> X >> A >> B >> C >> D;
        v.push_back(stu(X, A, B, C, D));
    }
    
    sort(v.begin(), v.end(), comp1);
    cout << v.back().X << ' ';
    v.pop_back();

    sort(v.begin(), v.end(), comp2);
    cout << v.back().X << ' ';
    v.pop_back();

    sort(v.begin(), v.end(), comp3);
    cout << v.back().X << ' ';
    v.pop_back();

    sort(v.begin(), v.end(), comp4);
    cout << v.back().X;
}
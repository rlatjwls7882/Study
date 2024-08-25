#include <bits/stdc++.h>
using namespace std;

bool visited[800];
int A[400][2], B[800];
vector<vector<int>> conn(400);

int changeStartIdx(int cur) {
    for(int i=0;i<A[B[cur]][0];i++) {
        if(B[i]==-1 && i!=cur) return i;
    }
    return -1;
}

bool dfs(int cur) {
    visited[cur]=true;
    for(int next:conn[cur]) {
        if(B[next]!=-1 && A[B[next]][1] == next) {
            int idx = changeStartIdx(next);
            if(idx==-1) continue;
            A[B[next]][1]=idx;
            B[idx]=B[next];
            B[next]=-1;
        }
        if(B[next]==-1 || !visited[B[next]] && dfs(B[next])) {
            int tmpa=A[cur][0], tmpb=B[next];
            A[cur][0]=next;
            B[next]=cur;
            if(A[cur][1]==-1) {
                int idx = changeStartIdx(next);
                if(idx==-1) {
                    A[cur][0]=tmpa;
                    B[next]=tmpb;
                    continue;
                }
                A[cur][1]=idx;
                B[idx]=cur;
            }
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<K;j++) {
            bool M; cin >> M;
            if(M) conn[i].push_back(j);
        }
    }

    int cnt=0;
    fill_n(&A[0][0], 800, -1);
    fill(B, B+800, -1);
    for(int i=0;i<N;i++) {
        if(A[i][0]==-1) {
            fill(visited, visited+800, false);
            if(dfs(i)) cnt++;
        }
    }
    cout << cnt;
}
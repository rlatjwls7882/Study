#include<bits/stdc++.h>
#define MAX 402
#define INF 10000000

int s=0, e=401;

using namespace std;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;

    int c[MAX][MAX] = {0, };
    int f[MAX][MAX] = {0, };
    vector<vector<int>> connect = vector<vector<int>>(MAX);

    for(int i=1;i<=2*N;i+=2) {
        c[s][i]=1;
        connect[s].push_back(i);
        connect[i].push_back(s);

        int Si; cin >> Si;
        while(Si-->0) {
            int num; cin >> num; num*=2;
            c[i][num]=c[num][e]=1;
            connect[i].push_back(num);
            connect[num].push_back(i);
            connect[num].push_back(e);
            connect[e].push_back(num);
        }
    }

    int total=0;
    while(true) {
        int prev[MAX]; fill(prev, prev+MAX, -1);
        queue<int> q; q.push(s);
        while(!q.empty() && prev[e]==-1) {
            int cur=q.front(); q.pop();
            for(int next:connect[cur]) {
                if(c[cur][next]-f[cur][next]>0 && prev[next]==-1) {
                    prev[next]=cur;
                    q.push(next);
                    if(next==e) break;
                }
            }
        }
        if(prev[e]==-1) break;

        int flow=INF;
        for(int i=e;i!=s;i=prev[i]) {
            flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
        }
        for(int i=e;i!=s;i=prev[i]) {
            f[prev[i]][i]+=flow;
            f[i][prev[i]]-=flow;
        }
        total+=flow;
    }
    cout << total;
}
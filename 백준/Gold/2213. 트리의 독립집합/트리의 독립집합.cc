#include <bits/stdc++.h>
using namespace std;

int w[10000];
bool visited[10000] = {false, };
int maxW[10000][2] = {0, }; // includeCur, excludeCur
vector<set<int>> visitNode1(10000);
vector<set<int>> visitNode2(10000);
vector<vector<int>> conn(10000);

void dfs(int cur) {
    visited[cur]=true;
    maxW[cur][0] = w[cur];
    visitNode1[cur].insert(cur+1);
    for(int next:conn[cur]) {
        if(!visited[next]) {
            dfs(next);

            if(conn[next].size()==1) {
                maxW[cur][1] += maxW[next][0];
                visitNode2[cur].merge(visitNode1[next]);
            } else {
                maxW[cur][0] += maxW[next][1];
                set<int> tmp = visitNode2[next];
                visitNode1[cur].merge(tmp);

                if(maxW[next][0]>maxW[next][1]) {
                    maxW[cur][1] += maxW[next][0];
                    visitNode2[cur].merge(visitNode1[next]);
                } else {
                    maxW[cur][1] += maxW[next][1];
                    visitNode2[cur].merge(visitNode2[next]);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        cin >> w[i];
    }

    for(int i=0;i<n-1;i++) {
        int u, v; cin >> u >> v;
        conn[u-1].push_back(v-1);
        conn[v-1].push_back(u-1);
    }
    dfs(0);

    if(maxW[0][0]>maxW[0][1]) {
        cout << maxW[0][0] << '\n';
        for(int val:visitNode1[0]) cout << val << ' ';
    } else {
        cout << maxW[0][1] << '\n';
        for(int val:visitNode2[0]) cout << val << ' ';
    }
}
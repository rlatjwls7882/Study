#include<bits/stdc++.h>
using namespace std;

int N, M, cnt=0;
int m[50][50];
int roomSize[2501];
int visited[50][50] = {0, };

void flood_fill(int x, int y) {
    queue<pair<int, int>> q; q.push(make_pair(x, y));
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if(visited[cur.first][cur.second]) continue;
        visited[cur.first][cur.second]=cnt;
        roomSize[cnt]++;
        if(!(m[cur.first][cur.second]&1) && !visited[cur.first][cur.second-1]) q.push(make_pair(cur.first, cur.second-1));
        if(!(m[cur.first][cur.second]&2) && !visited[cur.first-1][cur.second]) q.push(make_pair(cur.first-1, cur.second));
        if(!(m[cur.first][cur.second]&4) && !visited[cur.first][cur.second+1]) q.push(make_pair(cur.first, cur.second+1));
        if(!(m[cur.first][cur.second]&8) && !visited[cur.first+1][cur.second]) q.push(make_pair(cur.first+1, cur.second));
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            cin >> m[i][j];
        }
    }

    int maxSize=0;
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if(!visited[i][j]) {
                cnt++;
                flood_fill(i, j);
                maxSize = max(maxSize, roomSize[cnt]);
            }
        }
    }
    cout << cnt << '\n' << maxSize << '\n';

    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            if(m[i][j]&1 && j-1>=0 && visited[i][j]!=visited[i][j-1]) maxSize = max(maxSize, roomSize[visited[i][j]]+roomSize[visited[i][j-1]]);
            if(m[i][j]&2 && i-1>=0 && visited[i][j]!=visited[i-1][j]) maxSize = max(maxSize, roomSize[visited[i][j]]+roomSize[visited[i-1][j]]);
            if(m[i][j]&4 && j+1<N && visited[i][j]!=visited[i][j+1]) maxSize = max(maxSize, roomSize[visited[i][j]]+roomSize[visited[i][j+1]]);
            if(m[i][j]&8 && i+1<M && visited[i][j]!=visited[i+1][j]) maxSize = max(maxSize, roomSize[visited[i][j]]+roomSize[visited[i+1][j]]);
        }
    }
    cout << maxSize;
}
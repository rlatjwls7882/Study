#include<bits/stdc++.h>
using namespace std;

bool dislike[7][7];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<set<int>> teams;
    vector<pair<int, int>> cnt;
    for(int i=0;i<n;i++) cnt.push_back({0, i});
    while(m-->0) {
        int a, b; cin >> a >> b;
        dislike[a-1][b-1]=true;
        dislike[b-1][a-1]=true;
        cnt[a-1].first++;
        cnt[b-1].first++;
    }
    sort(cnt.begin(), cnt.end());

    for(int i=0;i<n;i++) {
        bool chk=false;
        for(int j=0;j<teams.size();j++) {
            bool notDislike=true;
            for(int people:teams[j]) {
                if(dislike[cnt[i].second][people]) {
                    notDislike=false;
                    break;
                }
            }
            if(notDislike) {
                chk=true;
                teams[j].insert(cnt[i].second);
                break;
            }
        }
        if(!chk) teams.push_back({cnt[i].second});
    }

    cout << teams.size() << '\n';
    for(int i=0;i<teams.size();i++) {
        for(int people:teams[i]) {
            cout << people+1 << ' ';
        }
        cout << '\n';
    }
}
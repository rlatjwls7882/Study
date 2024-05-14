#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> P;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<char, P> l;
    l.insert(pair<char, P>('q', P(0, 0)));
    l.insert(pair<char, P>('w', P(0, 1)));
    l.insert(pair<char, P>('e', P(0, 2)));
    l.insert(pair<char, P>('r', P(0, 3)));
    l.insert(pair<char, P>('t', P(0, 4)));
    l.insert(pair<char, P>('a', P(1, 0)));
    l.insert(pair<char, P>('s', P(1, 1)));
    l.insert(pair<char, P>('d', P(1, 2)));
    l.insert(pair<char, P>('f', P(1, 3)));
    l.insert(pair<char, P>('g', P(1, 4)));
    l.insert(pair<char, P>('z', P(2, 0)));
    l.insert(pair<char, P>('x', P(2, 1)));
    l.insert(pair<char, P>('c', P(2, 2)));
    l.insert(pair<char, P>('v', P(2, 3)));

    map<char, P> r;
    r.insert(pair<char, P>('y', P(0, 5)));
    r.insert(pair<char, P>('u', P(0, 6)));
    r.insert(pair<char, P>('i', P(0, 7)));
    r.insert(pair<char, P>('o', P(0, 8)));
    r.insert(pair<char, P>('p', P(0, 9)));
    r.insert(pair<char, P>('h', P(1, 5)));
    r.insert(pair<char, P>('j', P(1, 6)));
    r.insert(pair<char, P>('k', P(1, 7)));
    r.insert(pair<char, P>('l', P(1, 8)));
    r.insert(pair<char, P>('b', P(2, 4)));
    r.insert(pair<char, P>('n', P(2, 5)));
    r.insert(pair<char, P>('m', P(2, 6)));

    char sl, sr; cin >> sl >> sr;
    string s; cin >> s;

    P posL=l[sl], posR=r[sr];
    int sum=s.length();
    for(int i=0;i<s.length();i++) {
        if(l.find(s[i])!=l.end()) {
            P nextPos = l[s[i]];
            sum += abs(posL.first-nextPos.first) + abs(posL.second-nextPos.second);
            posL=nextPos;
        } else {
            P nextPos = r[s[i]];
            sum += abs(posR.first-nextPos.first) + abs(posR.second-nextPos.second);
            posR=nextPos;
        }
    }
    cout << sum;
}
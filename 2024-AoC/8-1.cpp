/**
 *  Advent of Code 2024
 *  Day 8 - Part 1
 *  
 *  Answer: 409
 * 
 *  @author Kian Chua
 * 
 */

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

const int N = 50;

bool out(int x, int y) {
    if (0 > x || x >= N) { return true; }
    if (0 > y || y >= N) { return true; }

    return false;
}

void solve() {
    map<char, vector<pair<int,int> > > counter;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            if (c != '.') {
                if (counter.find(c) == counter.end()) { counter[c] = vector<pair<int,int> >(); }
                counter[c].pb(mp(i,j));
            }
        }
    }

    set<pair<int,int> > ans;
    for (auto entry : counter) {
        vector<pair<int,int> > coors = entry.s;
        int n = coors.size();

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                pair<int,int>  first = coors[i];
                pair<int,int>  second = coors[j];

                pair<int,int>  delta = mp(second.f - first.f, second.s - first.s);

                pair<int,int>  pre = mp(first.f - delta.f, first.s - delta.s);
                pair<int,int>  pos = mp(second.f + delta.f, second.s + delta.s);

                if (!out(pre.f, pre.s)) { ans.insert(pre); }
                if (!out(pos.f, pos.s)) { ans.insert(pos); }
            }
        }
    }


    cout << ans.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
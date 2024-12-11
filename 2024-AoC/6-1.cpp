/**
 *  Advent of Code 2024
 *  Day 6 - Part 1
 *  
 *  Answer: 5564
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

const int N = 130;

bool out(int x, int y) {
    if (0 > x || x >= N) { return true; }
    if (0 > y || y >= N) { return true; }

    return false;
}

void solve() {

    pair<int,int> pos;
    pair<int,int> del = mp(-1,0);

    set<pair<int, int> > places;

    vector<vector<char> > grid(N);
    for (int i = 0; i < N; i++) {
        grid[i].resize(N);
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '^') { 
                pos = mp(i,j); 
                grid[i][j] = '.';
            }
        }
    }

    while (!out(pos.f, pos.s)) {
        places.insert(pos);
        pair<int, int> nxt = mp(pos.f + del.f, pos.s + del.s);
        if (out(nxt.f, nxt.s)) { break; }

        if (grid[nxt.f][nxt.s] == '#') {
            del = mp(del.s, -del.f);
        } else {
            pos = nxt;
        }
    }

    cout << places.size() << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
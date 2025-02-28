/**
 *  Advent of Code 2024
 *  Day 12 - Part 1 & Part 2
 *  
 *  Part 1 Answer: 1431440
 *  Part 2 Answer: 869070
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

const int N = 140;

int explore(int i, int j, vector<vector<char> > &g, vector<vector<bool> > &e, set<pair<pair<int, int>, int> > &st) {
    e[i][j] = true;
    
    int wall = 4;
    int count = 1;
    if (i > 0) {
        if (g[i-1][j] ==  g[i][j]) { wall--; if (!e[i-1][j]) count += explore(i-1, j, g, e, st); }
        else { st.insert(mp(mp(i, j), 0)); } // wall north of (i,j)
    } else { st.insert(mp(mp(i, j), 0)); }

    if (i < N-1) {
        if (g[i+1][j] ==  g[i][j]) { wall--; if (!e[i+1][j]) count += explore(i+1, j, g, e, st); }
        else { st.insert(mp(mp(i, j), 2)); } // wall south of (i,j)
    } else { st.insert(mp(mp(i, j), 2)); }

    if (j > 0) {
        if (g[i][j-1] ==  g[i][j]) { wall--; if (!e[i][j-1]) count += explore(i, j-1, g, e, st); }
        else { st.insert(mp(mp(i, j), 3)); } // wall west of (i,j)
    } else { st.insert(mp(mp(i, j), 3)); }

    if (j < N-1) {
        if (g[i][j+1] ==  g[i][j]) { wall--; if (!e[i][j+1]) count += explore(i, j+1, g, e, st); }
        else { st.insert(mp(mp(i, j), 1)); } // wall east of (i,j)
    } else { st.insert(mp(mp(i, j), 1)); }

    return count;
}

void mergeEdges(set<pair<pair<int, int>, int> > &e, set<pair<pair<int, int>, int> > &m) {
    while (!e.empty()) {
        auto p = e.begin();
        auto v = *p;

        m.insert(v);
        e.erase(v);
        
        pair<int, int> d = (v.s % 2) ? mp(1, 0) : mp(0, 1);

        int i = 1;
        while (e.find( mp( mp( v.f.f + i*d.f, v.f.s + i*d.s), v.s) ) != e.end()) {
            e.erase( mp( mp( v.f.f + i*d.f, v.f.s + i*d.s), v.s) );
            i++;
        }

        i = 1;
        while (e.find( mp( mp( v.f.f - i*d.f, v.f.s - i*d.s), v.s) ) != e.end()) {
            e.erase( mp( mp( v.f.f - i*d.f, v.f.s - i*d.s), v.s) );
            i++;
        }
    }
}

void solve() {
    vector<vector<char> > grid(N);
    vector<vector<bool> > explored(N);
    for (int i = 0; i < N; i++) {
        grid[i].resize(N);
        explored[i].resize(N, false);
        for (int j = 0; j < N; j++) { cin >> grid[i][j]; }
    }

    ll first = 0;
    ll second = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!explored[i][j]) {
                set<pair<pair<int, int>, int> > edges;
                int count = explore(i, j, grid, explored, edges);
                first += (ll)edges.size() * count;

                set<pair<pair<int, int>, int> > merged; 
                mergeEdges(edges, merged);
                second += (ll)merged.size() * count;
            }
        }
    }

    cout << first << endl;
    cout << second << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
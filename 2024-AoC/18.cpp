/**
 *  Advent of Code 2024
 *  Day 18 - Part 1 & Part 2
 * 
 *  Part 1 Answer: 324
 *  Part 2 Answer: 46,23
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

const int N = 71;
const int K = 1024;
const int K_MAX = 3450;

void solve() {

    vector<vector<bool> > grid(N);
    vector<vector<bool> > expl(N);
    vector<vector<int > > dist(N);
    for (int i = 0; i < N; i++) { grid[i].resize(N, false); expl[i].resize(N, false); dist[i].resize(N, -1); }

    for (int _ = 0; _ < K; _++) {
        int a; cin >> a;
        char c; cin >> c; // dummy
        int b; cin >> b;

        grid[a][b] = true;
    }

    queue<pair<int, int> > bfs;
    expl[0][0] = true;
    dist[0][0] = 0;
    bfs.push(mp(0,0));

    while (!bfs.empty()) {
        pair<int, int> t = bfs.front(); bfs.pop();
        int i = t.f; int j = t.s;

        if (i > 0) {
            if (!grid[i-1][j] &&  !expl[i-1][j]) {
                expl[i-1][j] = true;
                dist[i-1][j] = dist[i][j] + 1;
                bfs.push(mp(i-1, j));
            }
        }

        if (i < N-1) {
            if (!grid[i+1][j] &&  !expl[i+1][j]) {
                expl[i+1][j] = true;
                dist[i+1][j] = dist[i][j] + 1;
                bfs.push(mp(i+1, j));
            }
        }

        if (j > 0) {
            if (!grid[i][j-1] &&  !expl[i][j-1]) {
                expl[i][j-1] = true;
                dist[i][j-1] = dist[i][j] + 1;
                bfs.push(mp(i, j-1));
            }
        }

        if (j < N-1) {
            if (!grid[i][j+1] &&  !expl[i][j+1]) {
                expl[i][j+1] = true;
                dist[i][j+1] = dist[i][j] + 1;
                bfs.push(mp(i, j+1));
            }
        }
    }

    // FIRST ANSWER
    cout << dist[N-1][N-1] << endl;

    for (int k = K; k < K_MAX; k++) {
        int a; cin >> a; char c; cin >> c; int b; cin >> b;
        grid[a][b] = true;

        for (int i = 0; i < N; i++) { 
            for (int j = 0; j < N; j++) {
                expl[i][j] = false; 
                dist[i][j] = -1;
            }
        }

        // bfs should be empty
        expl[0][0] = true;
        dist[0][0] = 0;
        bfs.push(mp(0,0));  

        while (!bfs.empty()) {
            pair<int, int> t = bfs.front(); bfs.pop();
            int i = t.f; int j = t.s;

            if (i > 0) {
                if (!grid[i-1][j] &&  !expl[i-1][j]) {
                    expl[i-1][j] = true;
                    dist[i-1][j] = dist[i][j] + 1;
                    bfs.push(mp(i-1, j));
                }
            }

            if (i < N-1) {
                if (!grid[i+1][j] &&  !expl[i+1][j]) {
                    expl[i+1][j] = true;
                    dist[i+1][j] = dist[i][j] + 1;
                    bfs.push(mp(i+1, j));
                }
            }

            if (j > 0) {
                if (!grid[i][j-1] &&  !expl[i][j-1]) {
                    expl[i][j-1] = true;
                    dist[i][j-1] = dist[i][j] + 1;
                    bfs.push(mp(i, j-1));
                }
            }

            if (j < N-1) {
                if (!grid[i][j+1] &&  !expl[i][j+1]) {
                    expl[i][j+1] = true;
                    dist[i][j+1] = dist[i][j] + 1;
                    bfs.push(mp(i, j+1));
                }
            }
        } 

        if (dist[N-1][N-1] == -1) {
            cout << a << c << b << endl;
            break;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
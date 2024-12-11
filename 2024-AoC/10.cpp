/**
 *  Advent of Code 2024
 *  Day 10 - Part 1 & Part 2
 *  
 *  Part 1 Answer: 820
 *  Part 2 Answer: 1786
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

const int N = 55;

int search (int i, int j, vector<vector<char> > &g, set<pair<int, int> > &s) {

    // PART 1
    if (g[i][j] == '9') { return 1; }
    // PART 2
    if (g[i][j] == '9' && s.find(mp(i,j)) == s.end()) { s.insert(mp(i,j)); return 1; }


    int ans = 0;
    if (i > 0) {
        if ((int)(g[i-1][j] -  g[i][j]) == 1) { ans += search(i-1, j, g, s); }
    }

    if (i < N-1) {
        if ((int)(g[i+1][j] -  g[i][j]) == 1) { ans += search(i+1, j, g, s); }
    }

    if (j > 0) {
        if ((int)(g[i][j-1] -  g[i][j]) == 1) { ans += search(i, j-1, g, s); }
    }

    if (j < N-1) {
        if ((int)(g[i][j+1] -  g[i][j]) == 1) { ans += search(i, j+1, g, s); }
    }

    return ans;
}

void solve() {
    vector<vector<char> > grid(N);

    for (int i = 0; i < N; i++) {
        grid[i].resize(N);
        for (int j = 0; j < N; j++) { 
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '0') { 
                set<pair<int, int> > st;
                ans += search(i,j, grid, st); 
            }
        }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
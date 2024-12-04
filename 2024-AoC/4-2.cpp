/**
 *  Advent of Code 2024
 *  Day 4 - Part 2
 *  
 *  Answer: 1831
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

const int n = 140;
const vector<pair<int, int> > deltas = { mp(-1, -1), mp( 1,  1),
                                         mp( 1, -1), mp(-1,  1) };

bool out(int x, int y) {
    if (0 > x || x >= n) { return true; }
    if (0 > y || y >= n) { return true; }

    return false;
}

void solve() {
    vector<string> grid(n);
    for (int i = 0; i < n; i++) { cin >> grid[i]; }

    int ans = 0;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {

            if (grid[x][y] != 'A') { continue; }

            for (int i = 0; i < 2; i++) {
                int x1 = x + deltas[2*i].f;
                int y1 = y + deltas[2*i].s;

                int x2 = x + deltas[2*i + 1].f;
                int y2 = y + deltas[2*i + 1].s;

                if (out(x1,y1)) { break; }
                if (out(x2,y2)) { break; }

                char a = grid[x1][y1];
                char b = grid[x2][y2];

                if (min(a,b) != 'M') { break; }
                if (max(a,b) != 'S') { break; }

                if (i) { ans++; }
            }
        }
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
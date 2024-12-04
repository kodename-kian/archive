/**
 *  Advent of Code 2024
 *  Day 4 - Part 1
 *  
 *  Answer: 2336
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
const string key = "XMAS";
const vector<pair<int, int> > deltas = { mp(-1, -1), mp(-1,  0), mp(-1,  1),
                                         mp( 0, -1),             mp( 0,  1),
                                         mp( 1, -1), mp( 1,  0), mp( 1,  1) };

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
            for (pair<int, int> d : deltas) {
                for (int i = 0; i < 4; i++) {
                    int xp = x + d.f*i;
                    int yp = y + d.s*i;

                    if (out(xp, yp)) { break; }
                    if (grid[xp][yp] != key[i]) { break; }
                    
                    if (i == 3) { ans++; }
                }
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
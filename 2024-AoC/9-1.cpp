/**
 *  Advent of Code 2024
 *  Day 9 - Part 1
 *  
 *  Answer: 6349606724455
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

const int N = 1;

void solve() {
    string z; cin >> z;
    int n = z.length();

    vector<int> a;
    int dead = 0;
    int ind = 0;
    for (char c : z) {
        int ai = c - '0';
        for (int i = 0; i < ai; i++) { a.pb( dead ? -1 : ind); }

        if (!dead) { ind++; }
        dead = 1 - dead;
    }

    int s = 0;
    int e = a.size() - 1;
    while (s < e) {
        while (a[s] != -1) { s++; }
        while (a[e] == -1) { e--; }

        if (!(s < e)) { break; }

        swap(a[s], a[e]);
        s++; e--;
    }

    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != -1) { ans += i*a[i]; } 
        else { break; }
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
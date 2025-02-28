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

const int N = 2346;
const int T = 2000;

void solve() {

    ll part1 = 0;

    for (int _ = 0; _ < N; _++) {
        ll secret; cin >> secret;
        for (int i = 0; i < T; i++) { secret = generate(secret); }
        part1 += secret;
    }

    cout << part1 << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
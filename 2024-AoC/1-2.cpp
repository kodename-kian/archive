/**
 *  Advent of Code 2024
 *  Day 1 - Part 2
 *  
 *  Answer: 25574739
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

void solve() {
    int n = 1000;
    map<int, int> a, b;

    for (int i = 0; i < n; i++) {
        int ai, bi; cin >> ai >> bi;

        if (a.find(ai) == a.end()) { a[ai] = 0; }
        if (b.find(bi) == b.end()) { b[bi] = 0; }

        a[ai]++; b[bi]++; 
    }

    ll ans = 0;

    for (pair<ll,ll> p : a) {
        if (b.find(p.f) != b.end()) {
            ans += p.s * p.f * b[p.f];
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
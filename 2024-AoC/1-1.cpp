/**
 *  Advent of Code 2024
 *  Day 1 - Part 1
 *  
 *  Answer: 1603498
 * 
 *  @author Kian Chua
 * 
 */

#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

void solve() {
    int n = 1000;
    vector<int> a, b;

    for (int i = 0; i < n; i++) {
        int ai, bi; cin >> ai >> bi;
        a.pb(ai); b.pb(bi);  
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ans += abs(a[i]-b[i]);
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
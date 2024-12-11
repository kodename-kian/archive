/**
 *  Advent of Code 2024
 *  Day 11 - Part 1 & Part 2
 *  
 *  Part 1 Answer: 197357
 *  Part 2 Answer: 234568186890978
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

vector<ll> a = { 4610211, 4, 0, 59, 3907, 201586, 929, 33750 };
map<pair<ll, int>, ll> memo;

int digits (ll n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    
    return count;
}

ll blink (ll n, int c) {
    // edge cases
    if (memo.find(mp(n,c)) != memo.end()) { return memo[mp(n,c)]; }
    if (c == 0) { return 1; }

    ll ret;
    if (n == 0) { ret = blink(1, c-1); }
    else if (digits(n) % 2 == 0) {
        int d = digits(n);
        ret = blink(n / pow(10, d/2), c-1) + blink(n % (ll)pow(10, d/2), c-1);
    } else {
        ret = blink(n * 2024, c-1);
    }

    // memoize
    memo[mp(n,c)] = ret;
    return ret;
}

void solve() {

    int t; cin >> t;   // Part 1: t = 25;   Part 2: t = 75
    ll ans = 0;
    
    for (ll ai : a) { ans += blink(ai, t); }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
/**
 *  Advent of Code 2024
 *  Day 7 - Part 2
 *  
 *  Answer: 97902809384118
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

const int N = 850;

ll concat(ll a, ll b) {
    if (b == 0) { return 10*a; }

    ll c = b;
    ll i = 0;
    while (c) { i++; c /= 10; }

    a *= pow(10, i);
    a += b;

    return a;
}

bool check(ll s, vector<ll> &a) {
    int n = a.size();

    for (ll bit = 0; bit < (ll)(pow(3,n-1)); bit++) {
        ll use = bit;
        ll res = a[0];
        for (int i = 1; i < n; i++) {
            if (use % 3 == 0) { // multiply
                res *= a[i];
            } else if (use % 3 == 1) { // add
                res += a[i];
            } else { // concat
                res = concat(res, a[i]);
            }
            use /= 3;
        }
        if (res == s) { return true; }
    }

    return false;
}

void solve() {

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        // read input
        string line;
        getline(cin, line);

        // initialize string stream
        stringstream ss(line);

        ll s; ss >> s;   // answer
        char c; ss >> c;  // dummy :

        vector<ll> a;
        ll temp;
        while (ss >> temp) { a.pb(temp); }

        if (check(s, a)) { ans += s; }
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
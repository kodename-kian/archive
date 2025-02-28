#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

void solve() {
    ll n, p, x, y, c, d; cin >> n >> p >> x >> y >> c >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) { ll j, k; cin >> j >> k; a[i] = j+k; }
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    ll f = 0;
    for (int i = 0; i < p; i++) { f += a[i]; }
    f += x + y;

    ll ans = ((f+1)/2) * (f/2);

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) { solve(); }
}
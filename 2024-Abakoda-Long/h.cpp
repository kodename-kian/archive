// unfinished solution!

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

void attempt(ll a, ll b, ll c, vector<pair<ll,ll> > &best) {

    ll r = 5*b - 7*a - c;
    if (abs(r) % 3 != 0) { return; }   // no solution can be constructed

    ll S = max(a, max(b, c)) + 1;
    while ((3*S-r) % 18 != 0) { S++; }

    ll Z = (3*S-r)/18;
    ll Y = S + b - 2*a - 5*Z;
    while (Y < 0) {
        S += 6;
        Z = (3*S-r)/18;
        Y = S + b - 2*a - 5*Z;
    }

    ll X = 3*a - S - 2*b + 7*Z;

    vector<pair<ll, ll> > construct;
    if (X != 0) {
        construct.pb(mp(X, 123));
    }

    if (Y != 0) {
        construct.pb(mp(Y, 231));
    }

    if (Z != 0) {
        construct.pb(mp(Z, 312));
    }

    if (best.size() == 0 || (best.size() >= construct.size())) { 
        best = construct;
        cout << "INTENDED SUM: " << S << endl;
        cout << "XYZ: " << X << " " << Y << " " << Z << endl;
        cout << a + X + 2*Y + 3*Z << endl;
        cout << b + 2*X + 3*Y + Z << endl;
        cout << c + 3*X + Y + 2*Z << endl;
        cout << "==========" << endl;
    }

    return;
}

void solve() {

    ll a, b, c; cin >> a >> b >> c;
    vector<pair<ll, ll> > best;

    attempt(a,b,c,best);
    attempt(a,c,b,best);
    attempt(b,a,c,best);
    attempt(b,c,a,best);
    attempt(c,a,b,best);
    attempt(c,b,a,best);

    if (best.size() == 0) {
        cout << -1 << endl;
    } else {
        cout << best.size() << endl;
        for (auto p : best) {
            cout << p.f << endl;
            cout << p.s << endl;
        } 
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; cin >> t;
    while (t--) { solve(); }
}
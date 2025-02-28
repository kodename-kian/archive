#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

void solve() {
    ll n; int q; cin >> n >> q;

    set<ll> no, maybe;

    while(q--) {
        int k; cin >> k;
        vector<ll> a(k); for (int i = 0; i < k; i++) { cin >> a[i]; }
        int S; cin >> S;

        if (S == 2*k) { // every value is DEFINITELY not fake
            for (int i : a) { 
                no.insert(i); 
                if (maybe.find(i) != maybe.end()) { maybe.erase(i); }
            }
        } else if (S == 2*k - 1) { // one of these values IS the fake
            if (maybe.empty()) { // no 'maybe's have been processed yet
                for(int i : a) { if (no.find(i) == no.end()) maybe.insert(i); } 
            } else { // there already exist some 'maybe's
                set<ll> newMaybe;
                for (int i : a) {
                    if (no.find(i) != no.end()) { continue; }
                    if (maybe.find(i) != maybe.end()) { newMaybe.insert(i); }
                    else { no.insert(i); }
                }
                for (int i : maybe) {
                    if (newMaybe.find(i) == newMaybe.end()) { no.insert(i); }
                }
                maybe = newMaybe;
            }
        }
    }

    ll YES, NO, MAYBE;
    if (maybe.empty()) { // 0 YES, n-no MAYBEs, no NO
        YES = 0;
        NO = no.size();
        MAYBE = n - no.size();
    } else if (maybe.size() == 1) { // 1 YES, 0 MAYBEs, n-1 NO
        YES = 1;
        NO = n-1;
        MAYBE = 0;
    } else { // 0 YES, maybe MAYBEs, n-maybe NO
        YES = 0;
        NO = n-maybe.size();
        MAYBE = maybe.size();
    }

    if (MAYBE == 1) {
        YES = 1; MAYBE = 0;
    }

    cout << YES << " " << NO << " " << MAYBE << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while (t--) { solve(); }
}
/*
 * @author Kian Chua
 * @date 03/2025
 *
*/

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
 
using namespace std;

// using a standard lazy segment tree implementation
#include "LazySegmentTree.cpp"     // make it your own!

// for more detailed solution explanations & annotations
// refer to `senorita.cpp` first!
tuple<int, int, int> shirtsToMove(int current, int target) {
    if (target > current) { return mt(current+1, target-1, target-1); }
    else { return mt(target+1, current, target); }
}
 
// the formula:
//   the cost if shirt `k` is skipped = (
//      total cost without skipping shirts
//      - the cost of moving from shirt `k-1` to shirt `k`
//      - the cost of moving from shirt `k` to shirt `k+1`
//      + the cost of directly moving from shirt `k-1` to `k+1`
//      + the number of times shirt `k` is moved starting from `i=k+2` onwards 
//   )
void solve() {
    int m, n; 
    map<int, int> shirtToIndex;

    cin >> m;
    for (int i = 0; i < m; i++) { int s; cin >> s; shirtToIndex[s-1] = i;}
    cin >> n; 
    for (int i = 0; i < n; i++) { int s; cin >> s; shirtToIndex[s-1] = n+m-1-i;}

    int cur = m-1;              // [cur=i] => currently in-between shirts [i] and [i+1]
    int nxt;

    // dummy array of 1s and 0s to init segtrees
    vector<ll> a(m+n, 1);
    vector<ll> b(m+n, 0);

    // segment trees
    LazySegmentTree st(a);      // for calculating `costs` and `skips`
    LazySegmentTree lst(b);     // for calculating `bonus`

    vector<ll> costs(m+n, 0);   // costs[i] is the cost of going from shirt `i-1` to shirt `i` (0 <= i < m+n)
    vector<ll> skips(m+n, 0);   // skips[i] is the cost of going from shirt `j-1` to shirt `j+1` (0 <= j < m+n-1)
    vector<ll> bonus(m+n, 0);   // bonus[i] is the 'lingering' effect of shirt [k] not being removed when it should've been
                                //          in particular, leaving shirt `k` will impact `i=k+1` onwards, 
                                //          however, the cost for `i=k+1` is already accounted for in skips[k]
                                //          hence, bonus[k] must count from `i=k+2`, onwards (0 <= k < m+n-2) 

    vector<pair<int, int> > record;  // a record of the indices traversed at each step,
                                     // to be processed in reverse to compute for bonus[] values
    
    // for a given `i` from [0, m+n-1]: 
    //   calculate the cost of going from shirt `i-1` to shirt `i`
    //   calculate the cost of going from shirt `i-1` to shirt `i+1`                      
    for (int i=0; i < m+n; i++) {
        ll cost_i = 0;
        nxt = shirtToIndex[i];

        // solve for costs[i] -- refer to senorita.cpp for extra detail
        auto [startShirt, endShirt, nxtPosition] = shirtsToMove(cur, nxt);
        if (startShirt <= endShirt) { cost_i = st.query(startShirt, endShirt); }
        costs[i] = cost_i;

        record.pb(mp(startShirt, endShirt));  // record the range of shirts moved
        
        // detour to compute for skips[i],
        // using the exact same process, except without updating `st` or `cur`
        if (i < m+n-1) {
            ll skips_i = 0;
            int skips_nxt = shirtToIndex[i+1];  // jump forward to this shirt

            tuple<int, int, int> skips_shirts = shirtsToMove(cur, skips_nxt);
            int skipsStart = get<0>(skips_shirts);
            int skipsEnd = get<1>(skips_shirts);
            if (skipsStart <= skipsEnd) { skips_i = st.query(skipsStart, skipsEnd); }

            skips[i] = skips_i;
        }

        // set-up for next iteration
        st.update(nxt, -1);
        cur = nxtPosition;
    }

    // "base" answer, assuming no shirts are skipped
    ll original_answer = 0;
    for (auto i : costs) { original_answer += i; }

    // for a given `i` from [0, m+n-3], backwards: 
    //   calculate the "bonus" appearances of shirt `i`
    for (int i = m+n-3; i >= 0; i--) {
        // re-apply the shirt movements using lazy propagation
        // in reverse order, starting from the last move =m+n-1
        pair<int, int> move = record[i+2];
        if (move.f <= move.s) { lst.update(move.f, move.s, 1); }

        // query the number of times shirt `i` was moved up until this point
        bonus[i] = lst.query(shirtToIndex[i]);
    }
    
    // print answers, following the formula above
    for (int i = 0; i < n+m; i++) {
        cout << (
            original_answer 
            - costs[i] 
            - (i < m+n-1 ? costs[i+1] : 0) 
            + skips[i] 
            + bonus[i] 
        ) << " ";
    } cout << endl;

    return;
 }
 
 int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t = 1; cin >> t;
    while (t--) { solve(); }
 }
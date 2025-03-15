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

// using a standard segment tree implementation
#include "SegmentTree.cpp"         // make it your own!

// helper function -- extracted to separate logic & to re-use functionality
//   INPUTS:  
//     - current : current position, i.e. we are in-between shirts [c] and [c+1]
//     - target  : target  position, i.e. where the next shirt is
//   OUTPUTS: 
//     - startShirt  : the left-most shirt in the array that has to be moved
//     - endShirt    : the right-most shirt in the array that has to be moved
//     - nxtPosition : the new value for `current` after we move towards `target`
tuple<int, int, int> shirtsToMove(int current, int target) {
    if (target > current) { return mt(current+1, target-1, target-1); }
    else { return mt(target+1, current, target); }
}
 
void solve() {
    int m, n; 
    map<int, int> shirtToIndex;    // maps shirt number to array index

    cin >> m;
    for (int i = 0; i < m; i++) { int s; cin >> s; shirtToIndex[s-1] = i; }
    cin >> n; 
    for (int i = 0; i < n; i++) { int s; cin >> s; shirtToIndex[s-1] = n+m-1-i; }
    
    // indexes to mark the position of the `divide` in the stack
    int cur = m-1;                 // [cur=i] => in-between shirts [i] and [i+1]
    int nxt;                       // to be used during processing

    vector<ll> a(m+n, 1);          // dummy array of 1s to init segtree
    SegmentTree st(a);             // initialize SegmentTree
    vector<ll> costs(m+n);         // costs[i] is the cost of going from shirt `i-1` to shirt `i`, (0 <= i < m+n)
    
    // for a given `i` from [0, m+n-1]: 
    //   calculate the cost of going from shirt `i-1` to shirt `i`
    for (int i=0; i < m+n; i++) {
        ll cost_i = 0;
        nxt = shirtToIndex[i];     // get index of destination shirt

        // find the range of shirts that must be moved
        auto [startShirt, endShirt, nxtPosition] = shirtsToMove(cur, nxt);

        // count the number of shirts in range that are still in the pile
        if (startShirt <= endShirt) { cost_i = st.query(startShirt, endShirt); }

        costs[i] = cost_i;         // save cost
        st.update(nxt, -1);        // remove shirt from stack
        cur = nxtPosition;         // update index of current location
    }

    // sum up the costs incurred at each step
    ll ans = 0;
    for (auto i : costs) { ans += i; } 
    cout << ans << endl;

    return;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int t = 1; //cin >> t;
    while (t--) { solve(); }
}
/*
 * @author Kian Chua
 * @date 01/2025
 *
*/

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int n;
ll swaps_mn = 0, swaps_mx = 0;

vector<vector<int> > connect;      // edges
vector<bool> visited;              // visited status
vector<int>  parent;               // parent of node:         root has parent  = -1
vector<int>  depth;                // depth of node:          leafs have depth =  0
vector<int>  sze;                  // size of subtree         leafs have size  =  1
vector<int>  preorder;             // pre-order sort of graph

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;  // sort nodes by depth

void dfs(int i, int p) {
    visited[i] = true;
    parent[i] = p;
    preorder.pb(i);

    int depth_i = 0;
    int sze_i = 1;
    for (int j : connect[i]) {
        if (!visited[j]) {
            dfs(j, i);
            depth_i = max(depth_i, depth[j]+1);
            sze_i += sze[j];
        }
    }

    depth[i] = depth_i;
    sze[i] = sze_i;

    swaps_mx += min(sze_i, n-sze_i);    // count for MAX case

    pq.push(mp(depth_i, i));
}

void solve() {
    cin >> n;
    connect.resize(n);
    visited.resize(n, false);
    parent.resize(n);
    depth.resize(n);
    sze.resize(n, 0);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        connect[a].pb(b);
        connect[b].pb(a);
    }

    dfs(0, -1);

    vector<int> smallest(n), largest(n);
    for (int i = 0; i < n; i++) { smallest[i] = i+1; }

    while (!pq.empty()) {
        int cur = pq.top().s; pq.pop();

        // reuse visited to mark processed nodes
        // this time: processed => false
        if (!visited[cur]) { continue; }
        if (cur == 0) { // special handling for root
            swaps_mn++;
            swap(smallest[cur], smallest[connect[cur][0]]);
            continue;
        }

        visited[cur] = false;
        visited[parent[cur]] = false;

        // swap with parent
        swaps_mn++;                                    // count for MIN case
        swap(smallest[cur], smallest[parent[cur]]);    // construct for MIN case
    }

    // construct for MAX case
    for (int i = 0; i < n; i++) {  largest[preorder[i]] = preorder[(i+(n/2))%n] + 1; }

    cout << 2*swaps_mn << " " << 2*swaps_mx << endl;
    for (int i : smallest) { cout << i << " "; } cout << endl;
    for (int i : largest)  { cout << i << " "; } cout << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) { solve(); }
}
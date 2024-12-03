#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

int n;
vector<int> c;
vector<vector<pair<int, int> > > connect;
vector<int> ans;
map<int, int> world;
vector<bool> explored;

map<int,int> haynako(int i) {
	explored[i] = true;

	bool isLeaf = true;

	for (pair<int, int> r : connect[i]) {
		if (!explored[r.first]) { isLeaf = false; }
	}

	map<int, int> m = map<int,int>();
	if (isLeaf) { 
		m[c[i]] = 1;
		return m;
	} 

	// NOT A LEAF
	for (pair<int, int> r : connect[i]) {
		if (explored[r.first]) { continue; }
		
		map<int, int> contri = haynako(r.first);
		for (pair<int, int> p : contri) {

			ans[r.second] += (p.second * (world[p.first] - p.second));

			if (m.find(p.first) == m.end()) { m[p.first] = 0; }
			m[p.first] += p.second;
		}
	}

	// add existing city
	if (m.find(c[i]) == m.end()){ m[c[i]] = 0; }
	m[c[i]]++;
	return m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	c.resize(n); 
	for (int i = 0; i < n; i++) { 
		cin >> c[i]; 

		if (world.find(c[i]) == world.end()) { world[c[i]] = 0; }
		world[c[i]]++;
	}

	ans.resize(n-1, 0);
	connect.resize(n);
	explored.resize(n, false);

	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--; b--;
		connect[a].pb(mp(b, i));
		connect[b].pb(mp(a, i));
	}

	haynako(0);

	for (int a : ans) {
		cout << a << endl;
	}

	return 0;
}
/*
*  ICPC North America Qualifiers
*  10/5/24
*
*  Problem G - Gears and Axles
*  AC
* 
*  @author Kian Chua
*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	map<int, vector<double> > ayoh;

	for (int i = 0; i < n; i++) {
		int s, c; cin >> s >> c;
		if (ayoh.find(s) == ayoh.end()) {
			ayoh[s] = vector<double>();
		}
		ayoh[s].pb(c);
	}

	double ans = 0;

	for (pair<int, vector<double> > p : ayoh) {
		sort(p.second.begin(), p.second.end());
		if (p.second.size() <= 1) { continue; }

		for (int i = 0; i < p.second.size()/2; i++) {
			ans += log(p.second[p.second.size()-1-i]/p.second[i]);
		}
	}

	cout << setprecision(15) << ans << endl;

	return 0;
}
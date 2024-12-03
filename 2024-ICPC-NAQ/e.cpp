/*
*  ICPC North America Qualifiers
*  10/5/24
*
*  Problem E - Dishonest Lottery
*  AC
* 
*  @author Kian Chua
*/

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main() {
	int n; cin >> n;
	map<int, int> count;

	for (int i = 0; i < 10*n; i++) {
		for (int j = 0; j < 5; j++) {
			int x; cin >> x;

			if (count.find(x) == count.end()) {
				count[x] = 0;
			}

			count[x]++;
		}
	}

	vector<int> anuba;

	for (pair<int,int> val : count) {
		if (val.second > 2*n) {
			anuba.pb(val.first);
		}
	}

	sort(anuba.begin(), anuba.end());

	if (anuba.size() == 0) {
		cout << -1 << endl;
	} else {
		for (int k = 0; k < anuba.size(); k++ ) {
			cout << anuba[k];
			if (k == anuba.size()-1) { cout << endl; }
			else { cout << " "; }
		}
	}
	return 0;
}
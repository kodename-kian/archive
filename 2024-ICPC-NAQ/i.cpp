/*
*  ICPC North America Qualifiers
*  10/5/24
*
*  Problem I - Light Up
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
	
	vector<string> grid; grid.resize(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		grid[i] = s;
	}

	// cond 1: check all lit up
	vector<vector<bool> > lit;
	lit.resize(n);
	for (int i = 0; i < n; i++) { lit[i].resize(n, false);}

	// search for bulbs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '?') { // light bulb
				// check upward
				for (int ip = i-1; ip >= 0; ip--) {
					if (grid[ip][j] == '?') { cout << 0 << endl; return 0; }
					if (grid[ip][j] != '.') { break; }
					lit[ip][j] = true;
				}

				// check downward
				for (int ip = i+1; ip < n; ip++) {
					if (grid[ip][j] == '?') { cout << 0 << endl; return 0; }
					if (grid[ip][j] != '.') { break; }
					lit[ip][j] = true;
				}

				// check leftward
				for (int jp = j-1; jp >= 0; jp--) {
					if (grid[i][jp] == '?') { cout << 0 << endl; return 0; }
					if (grid[i][jp] != '.') { break; }
					lit[i][jp] = true;
				}

				// check rightward
				for (int jp = j+1; jp < n; jp++) {
					if (grid[i][jp] == '?') { cout << 0 << endl; return 0; }
					if (grid[i][jp] != '.') { break; }
					lit[i][jp] = true;
				}
			}
		}
	}

	// verify all lit
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '.' && !lit[i][j]) { cout << 0 << endl; return 0; }
		}
	}

	

	// cond 2: adjacent lights
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '0' ||
			    grid[i][j] == '1' ||
			    grid[i][j] == '2' ||
			    grid[i][j] == '3' ||
			    grid[i][j] == '4'   ) {

				// count the adjacent lights
				int cnt = 0;
				if (i > 0) { cnt += (grid[i-1][j] == '?'); }
				if (i < n-1) { cnt += (grid[i+1][j] == '?'); }
				if (j > 0) { cnt += (grid[i][j-1] == '?'); }
				if (j < n-1) { cnt += (grid[i][j+1] == '?'); }

				if (cnt != (int)(grid[i][j] - '0')) { cout << 0 << endl; return 0; }
			}
		}
	}




	cout << 1 << endl;
	return 0;
	
	
}
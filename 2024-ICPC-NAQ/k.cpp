/*
*  ICPC North America Qualifiers
*  10/5/24
*
*  Problem K - Rhythm Flow
*  AC
* 
*  @author Kian Chua
*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

int n, m;
vector<int> e, a;
vector<vector<int> > memo;

int score(int i, int j) {
	int diff = abs(e[i]-a[j]);

	if (0 <= diff && diff <= 15) { return 7; }
	else if (15 < diff && diff <= 23) { return 6; }
	else if (23 < diff && diff <= 43) { return 4; }
	else if (43 < diff && diff <= 102) { return 2; }

	return 0;
}

int dp(int i, int j) {
	if (i == n || j == m) { return 0;}

	if (memo[i][j] != -1) { return memo[i][j]; }

	// consider matching, consider not matching
	int match = score(i,j) + dp(i+1, j+1);
	int unmatch = max(dp(i+1, j), dp(i,j+1));

	memo[i][j] = max(match, unmatch);

	return max(match, unmatch);
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;

	memo.resize(n+1);
	for (int i = 0; i < n; i++) {
		memo[i].resize(m+1,-1);
	}

	e.resize(n);
	for (int i = 0; i < n; i++) { cin >> e[i]; }
	a.resize(m);
	for (int i = 0; i < m; i++) { cin >> a[i]; }

	cout << dp(0,0) << endl;
}
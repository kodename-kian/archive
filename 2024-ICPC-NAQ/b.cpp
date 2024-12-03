/*
*  ICPC North America Qualifiers
*  10/5/24
*
*  Problem B - Bikes and Barricades
*  AC
* 
*  @author Kian Chua
*/

#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main() {
	int n; cin >> n;
	vector<double> icp;

	for (int i = 0; i < n; i++) {
		double x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

		double m = (y2-y1)/(x2-x1);

		double b = -m*x1 + y1;

		if (min(x1,x2) <= 0 && max(x1,x2) >= 0) {
			icp.pb(b);
		}
	}

	sort(icp.begin(), icp.end());

	for (double d : icp) {
		if (d > 0) {
			cout << d << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}
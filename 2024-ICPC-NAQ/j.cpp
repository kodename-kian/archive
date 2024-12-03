/*
*  ICPC North America Qualifiers
*  10/5/24
*
*  Problem J - Menger Sponge
*  AC
* 
*  @author Kian Chua
*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;

int L;

ll gcd(ll a, ll b) {
	if (a == 0){ return b; }
	return gcd(b%a, a);
}

class Point {
	vector<ll> nums;
	vector<ll> dens;

	vector<ll> lbNums, ubNums, lbDens, ubDens;

	bool inDeadzone(int i, int L) {

		ll denCopy = dens[i]; int deg = 0;
		while (denCopy%3 == 0) { denCopy /= 3; deg++; }
		if (denCopy == 1 && deg <= L) { return false; }   // safe

		ll num = nums[i];
		ll den = dens[i];

		ll bln = 3*lbNums[i] + 1;
		ll bld = 3*lbDens[i];

		ll bun = 3*ubNums[i] - 1;
		ll bud = 3*ubDens[i];

		bool ans = (bln*den < bld*num && bud*num < bun*den); // CAUGHT IN THE DEADZONE

		// update restrictions for next cycle
		if (bld*num <= bln*den) {
			lbNums[i] *= 3;
			lbDens[i] *= 3;

			ubNums[i] = bln;
			ubDens[i] = bld;
		} else if (bun*den <= bud*num) {
			ubNums[i] *= 3;
			ubDens[i] *= 3;

			lbNums[i] = bun;
			lbDens[i] = bud;
		} else { // completely inside
			ubNums[i] = bun;
			ubDens[i] = bud;

			lbNums[i] = bln;
			lbDens[i] = bld;
		}

		return ans;
	}

public:
	Point() {
		nums.resize(3); dens.resize(3);
		for (int i = 0; i < 3; i++) { 
			cin >> nums[i] >> dens[i]; 

			ll g = gcd(nums[i], dens[i]); nums[i] /= g; dens[i] /= g;
			
			lbNums.pb(0);
			ubNums.pb(1);

			lbDens.pb(1);
			ubDens.pb(1);
		}
	}

	bool sponge(int L) {
		int counter = 0;
		for (int i = 0; i < 3; i++) {
			counter += inDeadzone(i, L);
		}
		return (counter >= 2);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> L;

	Point p = Point();

	for (int i = 1; i <= L; i++) {
		if (p.sponge(i)) {
			cout << 0 << endl; return 0;
		}
	}

	cout << 1 << endl;
	
	return 0;
}
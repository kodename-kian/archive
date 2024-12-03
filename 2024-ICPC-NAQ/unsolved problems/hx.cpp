#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;

class Creature {
	int a1, a2;

public:
	Creature(int n){ 
		a2 = n%20;
		n -= a2;
		a1 = n/20; 
	}

	bool hasChild(int b) {
		return (b == a1 || b == a2);
	}
};

class Zoo {
	int n;
	vector<int> z;

public: 
	Zoo(int n_) {n = n_; z.resize(n, 0);}

	vector<int> nextOption() {
		vector<int> ans = z;

		int ind = n-1;
		z[ind]++;
		z[ind] %= 20;

		while (z[ind] == 0) {
			ind--;
			z[ind]++;
			z[ind] %= 20;
		}

		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	Zoo zoo = Zoo(n);

	for (int i = 0; i < 400; i++) {
		for (int x : zoo.nextOption()) {
			cout << x << " ";
		} cout << endl;
	}

	return 0;
}
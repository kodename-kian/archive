/**
 *  Advent of Code 2024
 *  Day 5 - Part 2
 *  
 *  Answer: 5448
 * 
 *  @author Kian Chua
 * 
 */

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

bool isValid(vector<int> &a, map<int, vector<int> > &m) {
    set<int> done;
    for (int i : a) {
        for (int pre : m[i]) {
            if (find(a.begin(), a.end(), pre) == a.end()) { continue; }
            else if (done.find(pre) == done.end()) { return false; }
        }
        done.insert(i);
    }

    return true;
}

void fix(vector<int> &a, map<int, vector<int> > &m) {
    set<int> done;
    int j = 0;
    while (j < a.size()) {
        bool ok = true;
        int i = a[j];
        for (int pre : m[i]) {
            if (find(a.begin(), a.end(), pre) == a.end()) { continue; }
            else if (done.find(pre) == done.end()) { 
                auto it = find(a.begin(), a.end(), pre);
                swap(a[it - a.begin()], a[j]);
                ok = false;
            }
        }

        if (ok) {
            done.insert(i);
            j++;
        }
        
    }
    return;
}

int evaluate(vector<int> a, map<int, vector<int> > &m) {
    if (isValid(a,m)) { return 0; }
    fix(a, m);
    return a[a.size()/2];
}

vector<int> getQuery() {
    vector<int> a;

    bool expectC = false;
    while (true) {
        int ai; cin >> ai; a.pb(ai);
        if (cin.peek() != ',') { break; }
        char c; cin >> c; assert((void("wrong c"), c == ','));
    }

    return a;
}

void intake(map<int, vector<int> > &m) {
    int a; cin >> a;
    char c; cin >> c; assert((void("wrong c"), c == '|'));
    int b; cin >> b;

    if (m.find(b) == m.end()) { m[b] = vector<int>(); }
    m[b].pb(a);

    return;
}

void solve() {

    int m = 1176;
    int n = 1378 - m;

    map<int, vector<int> > preds;

    for (int i = 0; i < m; i++) { intake(preds); }

    int res = 0;
    for (int i = 0; i < n; i++) { res += evaluate(getQuery(), preds); }
    
    cout << res << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
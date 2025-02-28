#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

mt19937 rng(420);
vector<int> CODE[2];
const int d = 6;
const int n = 100;

void init() {
    CODE[0] = {0, 21, 42, 63, 3, 13, 26, 57};
    CODE[1] = {0, 21, 42, 63, 6, 37, 50, 60};
}

int diff(int x, int y) {
    int ans = 0;
    for (int j = 0; j < d; j++) { ans += (x%2 != y%2); x /= 2; y/= 2; }
    return ans;
}

string intToTF(int i) {
    string s = "";
    for (int j = 0; j < d; j++) { s += ((i%2) ? "T" : "F"); i /= 2 ; }
    // reverse(s.begin(), s.end());
    return s;
}

vector<int> convert(vector<int> p, int scheme) {
    vector<int> res;
    for (int i : p) {
        int best = 0;
        for (int j = 0; j < CODE[scheme].size(); j++) {
            if (diff(i, CODE[scheme][j]) < diff(i, CODE[scheme][best])) { best = j;}
        }
        res.pb(best);
    }
    return res;
}

string encode(string answer_key) {
    // break answer_key down into component pieces
    vector<int> pieces;
    for (int i = 4; i < n; i += 6) {
        int v = 0;
        for (int j = 5; j >= 0; j--) {        // encoded as: 654321
            v += (answer_key[i+j] == 'T');
            v *= 2;
        }
        v /= 2;
        pieces.pb(v);
    }

    // get 'best' encodings per scheme
    vector<int> schemeA = convert(pieces, 0);
    vector<int> schemeB = convert(pieces, 1);

    // grade each encoding, selecting best encoding scheme
    int penaltyA = 0, penaltyB = 0;
    for (int i = 0; i < pieces.size(); i++) {
        penaltyA += diff(pieces[i], CODE[0][schemeA[i]]);
        penaltyB += diff(pieces[i], CODE[1][schemeB[i]]);
    }

    vector<int> scheme = (penaltyB < penaltyA ? schemeB : schemeA);

    ll v = 0;
    for (int i = pieces.size() - 1; i >= 0; i--) { v += scheme[i]; v *= 8; } 
    v /= 8; v *= 2;

    // first four values
    for (int i = 3; i >= 0; i--) {
        v += (answer_key[i] == 'T');
        v *= 2;
    }

    // encoding scheme
    v += (penaltyB < penaltyA);

    // formatting return code
    string rCode = to_string(v);
    string trail = "0";
    while (rCode.length() < 16) { rCode.insert(0, trail); }

    return rCode;
}

string decode(string code) {
    ll v = stoll(code);

    string ans = "";

    int scheme = v % 2; v /= 2;

    for (int i = 0; i < 4; i++) {
        ans += ( (v%2) ? "T" : "F");
        v /= 2;
    }

    for (int i = 0; i < 16; i++) {
        int val = v % 8;
        v /= 8;
        ans += intToTF(CODE[scheme][val]);
    }

    return ans;
}
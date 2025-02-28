/**
 *  Advent of Code 2024
 *  Day 17 - Part 1 & Part 2
 *  
 *  ** INPUTS HARDCODED **
 * 
 *  Part 1 Answer: 1,5,0,1,7,4,1,0,3
 *  Part 2 Answer: 
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

ll A = 37293246;
ll B = 0;
ll C = 0;

// const vector<int> INS = {2, 4, 1, 6, 7, 5, 4, 4, 1, 7, 0, 3, 5, 5, 3, 0};
const vector<int> INS = {0,3,5,4,3,0};

ll combo (int arg) {
    switch(arg) {
        case 4:
            return A;
        case 5:
            return B;
        case 6:
            return C;
        case 7:
            cout << "INVALID COMBO" << endl;
            return -1;
        default:
            return arg;
    }
}

void run(vector<ll> &output) {
    int pc = 0;
    while (pc < INS.size()) {
        int OP = INS[pc];
        ll op;
        switch (OP) {
            case 0:
                op = combo(INS[pc+1]);
                op = pow(2, op);
                A /= op;
                break;
            case 1:
                op = INS[pc+1];
                B = B ^ op;
                break;
            case 2:
                B = combo(INS[pc+1]) % 8;
                break;
            case 3:
                if (A) { pc = INS[pc+1] - 2; }
                break;
            case 4:
                B = B ^ C;
                break;
            case 5:
                output.pb( combo(INS[pc+1]) % 8 );
                break;
            case 6:
                op = combo(INS[pc+1]);
                op = pow(2, op);
                B = A / op;
                break;
            case 7:
                op = combo(INS[pc+1]);
                op = pow(2, op);
                C = A / op;
                break;
            default:
                break;
        }
        
        pc += 2;

        if (output.size() > INS.size()) { break; }
    }
}

void solve() {

    vector<ll> partOne; 
    run(partOne);

    for (int i = 0; i < partOne.size(); i++) {
        cout << partOne[i] << ((i == partOne.size() -1 ) ? "" : ",");
    } cout << endl;

    ll partTwo = 1;
    ll sanity = 1;
    bool ok = false;

    while (!ok) {

        if (partTwo == sanity) {
            cout << "SANITY CHECK " << sanity << endl;
            sanity *= 2;
        }

        // reset registers
        A = partTwo;
        B = 0;
        C = 0;

        // run
        vector<ll> check;
        run(check);

        // verify
        if (check.size() == INS.size()) {
            bool flag = true;
            for (int i = 0; i < check.size(); i++) {
                flag = flag & (check[i] == INS[i]);
            }
            ok = ok | flag;
        }

        if (ok) { break; }
        partTwo++;
    }

    cout << partTwo << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
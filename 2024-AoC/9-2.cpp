/**
 *  Advent of Code 2024
 *  Day 9 - Part 2
 *  
 *  Answer: 6376648986651
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

class Node {
    public:
    int index;
    int length;
    Node *nxt;
    Node *pre;

    Node(int i, int l) {
        index = i;
        length = l;
        nxt = NULL;
        pre = NULL;
    }

    bool dead() { return index == -1; }
};

const int N = 1;

void solve() {
    string z; cin >> z;
    int n = z.length();

    int dead = 0;
    int ind = 0;

    Node *root = NULL;
    Node *prev = NULL;

    for (char c : z) {
        int ai = c - '0';

        Node *cur = new Node(dead ? -1 : ind, ai);

        if (root == NULL) { root = cur; }
        cur->pre = prev;
        if (prev != NULL) { prev->nxt = cur; }

        prev = cur;

        if (!dead) { ind++; }
        dead = 1 - dead;
    }

    // prev now contains the last Node
    while (prev != NULL) {
        if ((*prev).dead()) { prev = prev->pre; continue; }
        
        Node *cur = root;

        while (cur != prev) {
            if (!(*cur).dead()) { cur = cur->nxt; continue; }

            // it's a dead node
            if (cur->length == prev->length) {
                swap(cur->index, prev->index);
                break;
            } else if (cur->length > prev->length) {
                Node *insert = new Node(-1, cur->length - prev->length);
                insert->nxt = cur->nxt;
                cur->nxt->pre = insert;
                insert->pre = cur;
                cur->nxt = insert;

                cur->index = prev->index;
                cur->length = prev->length;

                prev->index = -1;
                break;
            } else {
                cur = cur->nxt;
            }
        }

        prev = prev->pre;
    }

    ll ans = 0;
    ll pos = 0;
    Node *cur = root;

    while (cur != NULL) {
        if (cur->dead()) {
            pos += cur->length;
            cur = cur->nxt;
            continue;
        }

        for (int i = 0; i < cur->length; i++) {
            ans += pos*cur->index;
            pos++;
        }

        cur = cur->nxt;
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;
    while (t--) { solve(); }
}
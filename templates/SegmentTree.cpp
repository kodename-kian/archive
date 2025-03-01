/*
 *  @author Kian Chua
 *  @date 2025/03
 * 
 *  ====================== Segment Tree ========================
 *  Standard implementation of a Segment Tree
 *  Specifications:
 *  - indices are numbered from [0 ... n-1]
 *  - supports point updates ONLY
 *  - supports point and range queries
 * 
 *  TODO: template to create a generic class
 *  ==========================================================
 */

#define ll long long

class SegmentTree {
    public:
        // constructor
        SegmentTree(vector<ll> &a) {
            n = a.size();
            segtree.resize(4*n, 0);
            buildTree(a, 0, 0, n-1);
        }

        // adds `d` to a[t]
        void update(int target, ll diff) {
            update(target, diff, 0, 0, n-1);
        }

        // returns the sum of a[l] + ... + a[r]
        ll query(int targetLft, int targetRgt) {
            return query(targetLft, targetRgt, 0, 0, n-1);
        }
    
    private: 
        int n;                // number of elements
        vector<ll> segtree;   // segment tree

        // Helper Functions
        int LFT(int i) { return 2*i + 1; }
        int RGT(int i) { return 2*i + 2; }
        int MID(int l, int r) { return (l+r)/2; }

        // Functionality
        void buildTree(vector<ll> &sourceArray, int index, int rangeLft, int rangeRgt) {
            if (rangeLft > rangeRgt) { return; }
            if (rangeLft == rangeRgt) { segtree[index] = sourceArray[rangeLft]; return; }

            buildTree(sourceArray, LFT(index), rangeLft                   , MID(rangeLft, rangeRgt));
            buildTree(sourceArray, RGT(index), MID(rangeLft, rangeRgt) + 1, rangeRgt               );
            segtree[index] = segtree[LFT(index)] + segtree[RGT(index)];
        }

        void update(int target, ll diff, int index, int rangeLft, int rangeRgt) {
            if (target < rangeLft || rangeRgt < target) { return; }
            if (rangeLft == rangeRgt && rangeLft == target) { segtree[index] += diff; return; }

            update(target, diff, LFT(index), rangeLft                   , MID(rangeLft, rangeRgt));
            update(target, diff, RGT(index), MID(rangeLft, rangeRgt) + 1, rangeRgt               );
            segtree[index] = segtree[LFT(index)] + segtree[RGT(index)];
        }
        
        ll query(int targetLft, int targetRgt, int index, int rangeLft, int rangeRgt) {
            if (targetRgt <  rangeLft || rangeRgt <  targetLft) { return 0; }
            if (targetLft <= rangeLft && rangeRgt <= targetRgt) { return segtree[index]; }

            return (
                query(targetLft, targetRgt, LFT(index), rangeLft                   , MID(rangeLft, rangeRgt)) +
                query(targetLft, targetRgt, RGT(index), MID(rangeLft, rangeRgt) + 1, rangeRgt               )
            );
        }
    
};
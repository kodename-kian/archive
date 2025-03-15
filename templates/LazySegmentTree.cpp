/*
 *  @author Kian Chua
 *  @date 2025/03
 * 
 *  ==================== Lazy Segment Tree ======================
 *  Standard implementation of a Lazy Segment Tree
 *  Specifications:
 *  - Indices are numbered from [0 ... n-1]
 *  - Supports point and range updates
 *  - Supports point and range queries
 *  - Assumes all given indices are valid
 *  - Array-based implementation
 * 
 *  TODO: template to create a generic class
 *  =============================================================
 */

#define ll long long

class LazySegmentTree {
    public:
        // constructor
        LazySegmentTree(vector<ll> &a) {
            n = a.size();
            segtree.resize(4*n, 0);
            lazy.resize(4*n, 0);
            buildTree(a, 0, 0, n-1);
        }
 
        // point update: adds `d` to a[t]
        void update(int target, ll diff) {
            update(target, target, diff, 0, 0, n-1);
        }

        // range update: adds `d` to a[l] ... a[r]
        void update(int targetLft, int targetRgt, ll diff) {
            update(targetLft, targetRgt, diff, 0, 0, n-1);
        }

        // point query: returns a[t]
        ll query(int target) {
            return query(target, target, 0, 0, n-1);
        }
 
        // range query: returns the sum of a[l] + ... + a[r]
        ll query(int targetLft, int targetRgt) {
            return query(targetLft, targetRgt, 0, 0, n-1);
        }
     
    private: 
        int n;                // number of elements
        vector<ll> segtree;   // segment tree
        vector<ll> lazy;      // lazy propagation
 
        // Helper Functions
        int LFT(int i) { return 2*i + 1; }
        int RGT(int i) { return 2*i + 2; }
        int MID(int l, int r) { return (l+r)/2; }

        // Apply `lazy` and propagate downwards 
        void pushDown(int index, int rangeLft, int rangeRgt) {
            if (lazy[index] == 0) { return; }

            segtree[index] += lazy[index] * (rangeRgt - rangeLft + 1);
            if (rangeLft != rangeRgt) {
                lazy[LFT(index)] += lazy[index];
                lazy[RGT(index)] += lazy[index];
            }
            lazy[index] = 0;
        }
 
        // Functionality
        void buildTree(vector<ll> &sourceArray, int index, int rangeLft, int rangeRgt) {
            if (rangeLft > rangeRgt) { return; }
            if (rangeLft == rangeRgt) { segtree[index] = sourceArray[rangeLft]; return; }
 
            buildTree(sourceArray, LFT(index), rangeLft                   , MID(rangeLft, rangeRgt));
            buildTree(sourceArray, RGT(index), MID(rangeLft, rangeRgt) + 1, rangeRgt               );
            segtree[index] = segtree[LFT(index)] + segtree[RGT(index)];
        }
 
        void update(int targetLft, int targetRgt, ll diff, int index, int rangeLft, int rangeRgt) {
            pushDown(index, rangeLft, rangeRgt);
            
            if (targetRgt < rangeLft || rangeRgt < targetLft) { return; }
            if (targetLft <= rangeLft && rangeRgt <= targetRgt) { 
                lazy[index] += diff; 
                pushDown(index, rangeLft, rangeRgt);
                return; 
            }
 
            update(targetLft, targetRgt, diff, LFT(index), rangeLft                   , MID(rangeLft, rangeRgt));
            update(targetLft, targetRgt, diff, RGT(index), MID(rangeLft, rangeRgt) + 1, rangeRgt               );
            segtree[index] = segtree[LFT(index)] + segtree[RGT(index)];
        }
         
        ll query(int targetLft, int targetRgt, int index, int rangeLft, int rangeRgt) {
            pushDown(index, rangeLft, rangeRgt);
            
            if (targetRgt <  rangeLft || rangeRgt <  targetLft) { return 0; }
            if (targetLft <= rangeLft && rangeRgt <= targetRgt) { return segtree[index]; }
 
            return (
                query(targetLft, targetRgt, LFT(index), rangeLft                   , MID(rangeLft, rangeRgt)) +
                query(targetLft, targetRgt, RGT(index), MID(rangeLft, rangeRgt) + 1, rangeRgt               )
            );
        }
     
 };
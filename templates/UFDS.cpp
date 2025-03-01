/*
 *  @author Kian Chua
 *  @date 2025/03
 * 
 *  ========================= UFDS ===========================
 *  Standard implementation of Union Find Disjoint Sets (DSU)
 *  Specifications:
 *  - Elements indexed from [0, n-1]
 *  - With path compression
 *  - Without union by rank/size
 *  ==========================================================
 */

class UFDS {
    private: vectorint> p;
    public:
        UFDS(int n) {
            p.resize(n);
            for (int i=0; i<n; i++) { p[i] = i; }
        }

        int parent(int i) {
            if (p[i] == i) { return i; }
            p[i] = parent(p[i]);
            return p[i];
        }

        void merge(int a, int b) {
            p[parent(b)] = parent(a);
        }
};
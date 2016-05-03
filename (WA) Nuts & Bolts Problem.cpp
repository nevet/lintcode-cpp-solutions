/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBoltsN2(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        int n = nuts.size();
        int m = bolts.size();
        
        for (int i = 0; i < n - 1; i ++) {
            int j = i;
            while (j < m && compare.cmp(nuts[i], bolts[j])) j ++;
            string temp = bolts[j];
            bolts[j] = bolts[i];
            bolts[i] = temp;
        }
        
        for (int i = 0; i < n; i ++) {
            printf("%s ", bolts[i].c_str());
        }
    }
    
    void swap(vector<string> &a, int l, int r) {
        if (l == r) return;
        
        string temp = a[l];
        a[l] = a[r];
        a[r] = temp;
    }
    
    void print(vector<string> &a) {
        for (int i = 0; i < a.size(); i ++) {
            printf("%s ", a[i].c_str());
        }
        printf("\n");
    }
    
    void sort(vector<string> &nuts, vector<string> &bolts, int left, int right, Comparator compare) {
        if (left >= right) return;
        
        fprintf(stderr, "%d %d ", left, right);
        
        int ni, nj, bi, bj, m;
        ni = bi = left; nj = bj = right;
        m = (left + right) >> 1;
        
        // recover bolts
        int bp = 0;
        while (bi < bj) {
            while (bi < bj && compare.cmp(nuts[m], bolts[bi]) < 0) bi ++;
            while (bi < bj && compare.cmp(nuts[m], bolts[bj]) > 0) bj --;
            
            if (compare.cmp(nuts[m], bolts[bi]) == 0) bp = bj; else
            if (compare.cmp(nuts[m], bolts[bj]) == 0) bp = bi;
            
            if (bi < bj) {
                swap(bolts, bi, bj);
                bi ++; bj --;
            }
            // print(bolts);
        }
        // printf("%d %d\n", bi, bp);
        while (compare.cmp(nuts[m], bolts[bi]) < 0) bi ++;
        fprintf(stderr, "%d %d ", bi, bp);
        if (bp < bi) { swap(bolts, bp, bi - 1); bp = bi - 1; } else
        if (bp > bi) { swap(bolts, bp, bi); bp = bi; }
        // print(bolts);
        
        // recover nuts
        swap(nuts, m, bp);
        m = bp;
        int np = 0;
        while (ni < m) {
            while (ni < m && compare.cmp(nuts[ni], bolts[m]) > 0) ni ++;
            while (ni < m && compare.cmp(nuts[nj], bolts[m]) < 0) nj --;
            
            if (ni < m) {
                swap(nuts, ni, nj);
                ni ++; nj --;
            }
        }
        // print(nuts);
        
        fprintf(stderr, "%d|", m);
        sort(nuts, bolts, left, m - 1, compare);
        sort(nuts, bolts, m + 1, right, compare);
    }
    
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        int n = nuts.size();
        // printf("zbh B: %d\n", compare.cmp("zbh", "B"));
        // printf("zbh T: %d\n", compare.cmp("zbh", "T"));
        // printf("zbh Q: %d\n", compare.cmp("zbh", "Q"));
        // printf("anj B: %d\n", compare.cmp("anj", "B"));
        // printf("anj T: %d\n", compare.cmp("anj", "T"));
        // printf("anj Q: %d\n", compare.cmp("anj", "Q"));
        // printf("lint B: %d\n", compare.cmp("lint", "B"));
        // printf("lint T: %d\n", compare.cmp("lint", "T"));
        // printf("lint Q: %d\n", compare.cmp("lint", "Q"));
        
        sort(nuts, bolts, 0, n - 1, compare);
        // sortNutsAndBoltsN2(nuts, bolts, compare);
    }
};
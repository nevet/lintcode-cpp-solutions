class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        if (A.size() != B.size()) return false;
        unordered_map<char, int> hash;
        for (int i = 0; i < A.size(); i ++) hash[A[i]] ++;
        for (int i = 0; i < B.size(); i ++) {
            if (hash.find(B[i]) == hash.end()) return false;
            hash[B[i]]--;
            if (hash[B[i]] == 0) hash.erase(B[i]);
        }
        
        return hash.empty();
    }
};
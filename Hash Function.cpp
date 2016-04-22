class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        int n = key.length();
        long long hash = 0;
        
        for (int i = 0; i < n; i ++) {
            hash = 33 * hash % HASH_SIZE;
            hash = (hash + key[i]) % HASH_SIZE;
        }
        
        return hash;
    }
};
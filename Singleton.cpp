class Solution {
private:
    Solution() {};
    ~Solution() {};
    
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        static Solution *instance = new Solution();
        
        return instance;
    }
};
// 6 wa
struct compare {
    bool operator() (string a, string b) {
        int m = min(a.length(), b.length());
        int i = 0;
        
        while (i < m) {
            if (a[i] < b[i]) return true;
            if (a[i] > b[i]) return false;
            
            i ++;
        }
        
        if (a.length() == b.length()) return true;
        
        if (a.length() > m) {
            return a[i] <= a[0];
        }
        
        return b[i] > b[0];
    }
} cmp;

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &nums) {
        vector<string> v;
        int n = nums.size();
        bool allz = true;
        
        for (int i = 0; i < n; i ++) {
            if (nums[i] != 0) allz = false;
            v.push_back(to_string(nums[i]));
        }
        
        if (allz) return "0";
        
        sort(v.begin(), v.end(), cmp);
        
        string s;
        
        for (int i = n - 1; i >= 0; i --) {
            s += v[i];
        }
        
        return s;
    }
};

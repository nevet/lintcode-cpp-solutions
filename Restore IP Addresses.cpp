class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> ips;
    
    string combine(vector<string> v, string last) {
        string ip = "";
        for (int i = 0; i < v.size(); i ++) {
            ip += v[i] + ".";
        }
        return ip + last;
    }
    
    void split(string &s, int cur, vector<string> ip) {
        int len = s.size();
        
        // if too many digits left, prune
        if (len - cur > (4 - ip.size()) * 3) return;
        // if too few digits left, prune
        if (len - cur < 4 - ip.size()) return;
        // if only 3 digits left, put it in
        if (ip.size() == 3 && len - cur <= 3) {
            if (len - cur > 1 && s[cur] == '0') return;
            
            string sub = s.substr(cur, len - cur);
            if (len - cur < 3 || stoi(sub) <= 255) ips.push_back(combine(ip, sub));
            return;
        }
        
        if (s[cur] == '0') {
            ip.push_back("0");
            split(s, cur + 1, ip);
            ip.pop_back();
            
            return;
        }
        
        for (int i = cur; i < cur + 3 && i < len; i ++) {
            // fprintf(stderr, "cur = %d i = %d ", cur, i);
            string sub = s.substr(cur, i - cur + 1);
            // fprintf(stderr, "s = %s ", sub.c_str());
            if (i < cur + 2 || stoi(sub) <= 255) ip.push_back(sub); else continue;
            split(s, i + 1, ip);
            ip.pop_back();
        }
    }
    
    vector<string> restoreIpAddresses(string& s) {
        vector<string> ip;
        split(s, 0, ip);
        return ips;
    }
};
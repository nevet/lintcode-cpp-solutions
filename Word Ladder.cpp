class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    typedef pair<string, int> si;
    
    string transform(string s, int p, int delta) {
        string t = s;
        t[p] = 'a' + delta;
        return t;
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<si> q;
        unordered_set<string> dup;
        
        if (start == end) return 1;
        
        q.push(si(start, 1));
        
        while (!q.empty()) {
            si head = q.front(); q.pop();
            
            for (int i = 0; i < head.first.size(); i ++) {
                for (int j = 0; j < 26; j ++) {
                    if (j + 'a' == head.first[i]) continue;
                    string transformed = transform(head.first, i, j);
                    
                    if (transformed == end) return head.second + 1;
                    
                    if (dup.find(transformed) == dup.end() &&
                        dict.find(transformed) != dict.end()) {
                            dup.insert(transformed);
                            q.push(si(transformed, head.second + 1));
                        }
                }
            }
        }
        
        return 0;
    }
};
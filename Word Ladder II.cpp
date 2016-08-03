bool f[100000][50], vis[100000][50];
vector<string> rec[100000];

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    typedef pair<string, int> si;
    
    string transform(string s, int p, int delta) {
        string t = s;
        t[p] = 'a' + delta;
        return t;
    }
    
    unordered_set<string> dup;
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<si> q;
        
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
    
    int findDiff(string start, string end) {
        int ans = 0;
        for (int i = 0; i < start.size(); i ++)
            if (start[i] != end[i]) ans ++;
        
        return ans;
    }
    
    void findAll(string s, string end, int olddiff, unordered_set<string> &dict, vector<si>& pos) {
        for (int i = 0; i < s.size(); i ++) {
            string next = s;
            for (int j = 0; j < 26; j ++) {
                int diff = olddiff;
                if (j + 'a' == s[i]) continue;
                next[i] = j + 'a';
                if (s[i] == end[i]) diff ++; else diff -= (next[i] == end[i]);
                if (dict.find(next) != dict.end() || next == end) pos.push_back(si(next, diff));
            }
        }
    }
    
    vector<vector<string> > ans;
    vector<vector<si> > poss;
    map<string, int> index;
    int tot = 0;
    
    bool dfs(string now, string end, unordered_set<string> &dict, int d, int diff) {
        // fprintf(stderr, "%s %d %d|", now.c_str(), d, diff);
        if (index.find(now) == index.end()) {
            vector<si> p;
            findAll(now, end, diff, dict, p);
            poss.push_back(p);
            index[now] = tot++;
        } else if (vis[index[now]][d]) return f[index[now]][d];
        
        int ind = index[now];
        vis[ind][d] = true;
        
        if (diff > d) return f[ind][d] = false;
        
        if (d == 0) {
            if (now == end) {
                rec[ind].push_back(now);
                return f[ind][d] = true;
            }
            
            return f[ind][d] = false;
        }
        
        for (int i = 0; i < poss[ind].size(); i ++) {
            string next = poss[ind][i].first;
            if (dup.find(next) == dup.end()) {
                dup.insert(next);
                if (dfs(next, end, dict, d - 1, poss[ind][i].second)) {
                    f[ind][d] = true;
                    rec[ind].push_back(next);
                };
                dup.erase(next);
                
                if (next == end) break;
            }
        }
        
        return f[ind][d];
    }
    
    void print(string cur, string end, vector<string> c) {
        int ind = index[cur];
        c.push_back(cur);
        for (int i = 0; i < rec[ind].size(); i ++) {
            if (cur == end) {
                ans.push_back(c);
                break;
            }
            print(rec[ind][i], end, c);
        }
        c.pop_back();
    }
    
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        int d = ladderLength(start, end, dict);
        
        memset(f, 0, sizeof(f));
        memset(vis, 0, sizeof(vis));
        
        dup.clear();
        dfs(start, end, dict, d - 1, findDiff(start, end));
        
        // for (int i = 0; i < tot; i ++) {
        //     for (int j = 0; j < rec[i].size(); j ++) {
        //         printf("%s ", rec[i][j].c_str());
        //     }
        //     printf("%d\n", (int)rec[i].size());
        // }
        
        vector<string> v;
        print(start, end, v);
        
        // for (int i = 0; i < poss.size(); i ++) {
        //     for (int j = 0; j < poss[i].size(); j ++) printf("%s ", poss[i][j].c_str());
        //     printf("\n");
        // }
        
        return ans;
    }
};
//"a", "c", ["a","b","c"]
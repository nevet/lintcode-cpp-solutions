class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    int tot;
    
    bool traverse(int pos, int prev, vector<bool> &mark, vector<vector<int>>& edges) {
        if (mark[pos]) return false;
        mark[pos] = true; tot ++;
        
        bool res = true;
        for (int i = 0; i < edges[pos].size(); i ++) {
            if (edges[pos][i] == prev) continue;
            res = res && traverse(edges[pos][i], pos, mark, edges);
        }
        
        return res;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> mark(n + 5, false);
        vector<vector<int> > adj(n + 5);
        tot = 0;
        for (int i = 0; i < edges.size(); i ++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        return traverse(0, -1, mark, adj) && n == tot;
    }
};
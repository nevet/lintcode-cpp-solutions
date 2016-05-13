/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        int n = graph.size();
        if (n <= 1) return graph;
        
        int ind[n + 5];
        memset(ind, 0, sizeof(ind));
        
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < graph[i]->neighbors.size(); j ++) {
                ind[graph[i]->neighbors[j]->label] ++;
            }
        }
        
        queue<DirectedGraphNode*> q;
        for (int i = 0; i < n; i ++) {
            if (ind[graph[i]->label] == 0) q.push(graph[i]);
        }
        
        vector<DirectedGraphNode*> ans;
        while (!q.empty()) {
            DirectedGraphNode* u = q.front();
            ans.push_back(u);
            q.pop();
            
            for (int i = 0; i < u->neighbors.size(); i ++) {
                ind[u->neighbors[i]->label]--;
                if (ind[u->neighbors[i]->label] == 0) {
                    q.push(u->neighbors[i]);
                }
            }
        }
        
        return ans;
    }
};
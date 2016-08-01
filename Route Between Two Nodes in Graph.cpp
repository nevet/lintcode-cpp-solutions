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
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    set<DirectedGraphNode*> vis;
    
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        if (s == NULL) return false;
        if (vis.find(s) != vis.end()) return false;
        vis.insert(s);
        if (s->label == t->label) return true;
        
        for (int i = 0; i < s->neighbors.size(); i ++) {
            if (hasRoute(graph, s->neighbors[i], t)) {
                return true;
            }
        }
        
        return false;
    }
};


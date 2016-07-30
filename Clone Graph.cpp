/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    map<int, UndirectedGraphNode*> hash;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        hash[node->label] = newNode;
        
        for (int i = 0; i < node->neighbors.size(); i ++) {
            if (hash.find(node->neighbors[i]->label) == hash.end()) {
                newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
            } else {
                newNode->neighbors.push_back(hash[node->neighbors[i]->label]);
            }
        }
        
        return newNode;
    }
};
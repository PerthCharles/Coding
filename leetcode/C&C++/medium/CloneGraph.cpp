/*
 *  Clone Graph
 *      Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 *
 *
 *      OJ's undirected graph serialization:
 *      Nodes are labeled uniquely.
 *
 *      We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
 *      As an example, consider the serialized graph {0,1,2#1,2#2,2}.
 *
 *      The graph has a total of three nodes, and therefore contains three parts as separated by #.
 *
 *      First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
 *      Second node is labeled as 1. Connect node 1 to node 2.
 *      Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
 */


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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return node;
        unordered_map<int, UndirectedGraphNode *> copied;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        copied[node->label] = new UndirectedGraphNode(node->label);
        
        while (!q.empty()) {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            
            for (auto nbr : cur->neighbors) {
                // node already existed
                if (copied.find(nbr->label) != copied.end()) {
                    copied[cur->label]->neighbors.push_back(copied[nbr->label]);
                } else {
                    UndirectedGraphNode *new_node = new UndirectedGraphNode(nbr->label);
                    copied[nbr->label] = new_node;
                    copied[cur->label]->neighbors.push_back(new_node);
                    q.push(nbr);
                }
            }
        }
        
        return copied[node->label];
    }
};
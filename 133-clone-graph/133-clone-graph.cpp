/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> graph;
    Node* cloneGraph(Node* node) {
        
        if(node == NULL) return NULL;
        if(graph[node]) return graph[node];
        Node* root = new Node(node->val);
        graph[node] = root;
        
        for(auto u: node->neighbors)
        {
            root->neighbors.push_back(cloneGraph(u));
        }
        
        return root;
        
    }
};
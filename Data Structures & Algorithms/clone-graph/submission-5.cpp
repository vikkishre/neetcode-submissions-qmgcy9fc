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
    unordered_map<Node*,Node*> m;
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        if(m.find(node)!=m.end())
        {
            return m[node];
        }
         Node* cloneNode=new Node(node->val);
         m[node]=cloneNode;
         for(auto neighbour: node->neighbors)
         {
            Node* child=cloneGraph(neighbour);
            cloneNode->neighbors.push_back(child);
         }
        return cloneNode;
    }
};

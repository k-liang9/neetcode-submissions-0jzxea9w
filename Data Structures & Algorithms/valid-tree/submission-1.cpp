class Node {
public:
    bool visited;
    vector<int> adj;

    Node() : visited(false){}
};

class Solution {
public:
    vector<Node> nodes;

    bool dfs(int cur, int parent) {
        if (nodes[cur].visited) {
            return false;
        }
        nodes[cur].visited = true;

        bool res = true;
        for (int adj : nodes[cur].adj) {
            if (adj == parent) {
                continue;
            }
            res &= dfs(adj, cur);
        }
        
        return res;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        //if there exists: loops or lone vertices, then the graph is not a valid tree
        //we can check if a loop exists using dfs, if dfs visits a node twice, then a loop exists, and thus it is not a valid tree
        nodes.resize(n);

        //node: O(V+E) space
        //  bool visited: O(V) space
        //  iterate through every edge to construct adjacency lists: O(E) space
        for (const vector<int>& edge : edges) {
            int a = edge.at(0);
            int b = edge.at(1);
            nodes[a].adj.push_back(b);
            nodes[b].adj.push_back(a);
        }

        //run dfs on node 0. a valid tree will be a valid tree no matter what node you start on: O(E) time
        //keep track of parent in dfs to ensure that you do not mistakenly count the parent as a loop
        //if visited during dfs, return false
        if (!dfs(0, -1)) return false;

        //iterate through every node's visited flag, if not visited, then return false, if visited, return true
        for (const Node& node : nodes) {
            if (!node.visited) {
                return false;
            }
        }
        return true;
    }
};

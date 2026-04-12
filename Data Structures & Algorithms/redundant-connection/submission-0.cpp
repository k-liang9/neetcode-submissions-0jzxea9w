class Node {
public:
    bool visited;
    vector<int> adj;

    Node() : visited(false) {}
};

class Solution {
public:
    vector<int> visited_nodes;
    vector<Node> nodes;

    bool dfs(int cur, int parent) {
        visited_nodes.push_back(cur);

        if (nodes[cur].visited) {
            return true;
        }

        //2. keep a list of traversed nodes (O(V+E))
        nodes[cur].visited = true;

        for (int adj : nodes[cur].adj) {
            if (adj == parent) {
                continue;
            }
            
            if (dfs(adj, cur)) {
                return true;
            }
        }

        visited_nodes.pop_back();

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //1. build graph (adjacency list)
        for (const vector<int>& edge : edges) {
            int a = edge.at(0);
            int b = edge.at(1);

            int max_size = max(a, b) + 1;
            if (max_size > nodes.size()) {
                nodes.resize(max_size);
            }

            nodes[a].adj.push_back(b);
            nodes[b].adj.push_back(a);
        }

        dfs(1, 0);

        //add all nodes in the cycle to a set, traverse backwards from the list of edges. if an edge's 2 vertices are in the set, then taht edge is guaranteed to be a part of the loop
        int last = visited_nodes[visited_nodes.size()-1];
        unordered_set<int> loop;
        loop.insert(last);
        for (int i = visited_nodes.size()-2; i >= 0 && visited_nodes[i] != last; i--) {
            loop.insert(visited_nodes[i]);
        }

        for (int i = edges.size()-1; i >= 0; i--) {
            int a = edges[i][0];
            int b = edges[i][1];

            if (find(loop.begin(), loop.end(), a) != loop.end() && find(loop.begin(), loop.end(), b) != loop.end()) {
                return edges[i];
            }
        }

        return vector<int>();
    }
};

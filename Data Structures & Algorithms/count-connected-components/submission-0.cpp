//create node class, which includes the adjacency list for that node and visited flag
class Node {
public:
    vector<int> adj;
    bool visited;

    Node() : visited(false) {}
};

class Solution {
public:
    //store all nodes in a vector (O(V) time, O(V) space)
    vector<Node> nodes;

    //dfs
    void dfs(int i) {
        //if node is visited, return
        //else, set visited flag to true, recursively traverse through adjacent vertex
        if (nodes[i].visited) {
            return;
        }

        nodes[i].visited = true;
        for (int adj : nodes[i].adj) {
            dfs(adj);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        nodes.resize(n);

        //iterate through every edge, add to adjacency list for that node (O(E) space & O(E) time)
        for (const vector<int>& edge : edges) {
            int a = edge.at(0);
            int b = edge.at(1);
            nodes[a].adj.push_back(b);
            nodes[b].adj.push_back(a);
        }

        //iterate through every vertex, if not visited, perform a traversal using that node, increment count by 1 (O(E))
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!nodes[i].visited) {
                res++;
                dfs(i);
            }
        }

        //return result
        return res;

        //O(V+E) space & time
    }
};

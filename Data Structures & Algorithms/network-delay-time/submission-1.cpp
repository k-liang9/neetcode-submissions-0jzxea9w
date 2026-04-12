class Solution {
public:
    class Node {
    public:
        vector<vector<int>> adj;
        int dist;
        int id;

        Node() : dist{INT_MAX}, id(-1) {}
        Node(int i, int distance) : id(i), dist(distance) {}

        bool operator<(const Node& other) const {
            return dist > other.dist;
        }
    };

    vector<Node> nodes;
    unordered_set<int> solved;
    priority_queue<Node> unsolved;

    void relax(int i) {
        cout << "relaxing vertex " << i << '\n';
        for (auto& edge : nodes[i].adj) {
            Node& dest = nodes[edge[0]];
            int cand_dist = nodes[i].dist + edge[1];
            cout << "\tother node: " << edge[0] << " cand dist: " << cand_dist << '\n';
            if (cand_dist < dest.dist) {
                dest.dist = cand_dist;
                unsolved.push(Node(edge[0], dest.dist));
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        nodes.assign(n, Node());
        for (int i = 0; i < n; i++) nodes[i].id = i;
        nodes[k-1].dist = 0;

        //match each directed edge to corresponding node
        for (auto& time : times) {
            nodes[time[0]-1].adj.push_back({time[1]-1, time[2]});
        }

        //add unsolved nodes to pq
        unsolved.push(Node(k-1, 0));

        //pop
        int max_time = 0;
        while (solved.size() < n && !unsolved.empty()) {
            int id = unsolved.top().id;
            unsolved.pop();

            if (find(solved.begin(), solved.end(), id) != solved.end()) {
                continue;
            }

            solved.insert(id);
            relax(id);
            max_time = nodes[id].dist;
        }

        return solved.size() == n ? max_time : -1;
    }
};


//dijkstra's
//1. keep a set of "finalized nodes", and a priority queue of nonfinalized nodes
//2. at each step, pop the priority queue, finalize the time to reach the node, add to set of "solved nodes"
//3. relax all of the edges for the newly added node


//todo: data structure to store adjacencies & min distance
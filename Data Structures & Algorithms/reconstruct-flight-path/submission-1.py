class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        adj = defaultdict(list)
        for src, dst in sorted(tickets)[::-1]:
            adj[src].append(dst)
        
        path = []
        def dfs(src):
            while adj[src]:
                dst = adj[src].pop()
                dfs(dst)
            path.append(src)

        dfs("JFK")
        return path[::-1]

# eulerian path: if a node has no more outgoing edges, then the node must be the end node of a sub-eulerian path
# construct the eulerian path from backwards
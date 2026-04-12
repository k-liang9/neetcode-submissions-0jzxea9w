class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        # every edge used once, starting from jfk
        adj = defaultdict(list)
        for begin, end in tickets:
            adj[begin].append(end)

        for start in adj:
            adj[start].sort()
            adj[start] = deque(adj[start])

        path = ['JFK']
        self.tickets_used = 0

        def dfs():
            if self.tickets_used == len(tickets):
                return True
            
            curr = path[-1]
            for _ in range(len(adj[curr])):
                dest = adj[curr].popleft()
                path.append(dest)
                self.tickets_used += 1
                if dfs():
                    return True
                self.tickets_used -= 1
                path.pop()
                adj[curr].append(dest)

            return False
        
        dfs()
        return path


# intermediate edges: edges coming in == edges going out
# start edge (jfk): edges coming in + 1 == edges going out
# end edge: edges coming in = 1 + edges going out
# can figure out start + end in O(E)
# is this the only condition for selecting a ticket to add? that if the dest city still has outs, one should always take that? answer is no:
# a <-> b -> c -> d
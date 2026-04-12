class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        # 1: initialize adjacencies O(n)
        edges = [[] for i in range(n)]
        for a, b, p in flights:
            edges[a].append((b, p))
        
        q = deque([[src, 0]])
        best = [-1 for i in range(n)]

        trips = 0
        while len(q) and trips < k+2:
            width = len(q)
            for _ in range(width):
                cur, cost = q.popleft()
                print(cur, cost)
                if best[cur] != -1 and best[cur] < cost:
                    continue
                best[cur] = cost
                if cur == dst:
                    continue
                for next_node, price in edges[cur]:
                    q.append([next_node, cost+price])
            trips += 1

        return best[dst]


#1: w/o k: dijkstra's
#2: w/o prices: bst
# no "best" way to get to a place, only the best way to get to a place in under i flights

# bst up to k iterations. if visited & best cost is less than current cost: skip this node
# visited means the previous visitation is better than the current visitation: fewer flights & cheaper, else queue again
# worst case: O(m*k + n)
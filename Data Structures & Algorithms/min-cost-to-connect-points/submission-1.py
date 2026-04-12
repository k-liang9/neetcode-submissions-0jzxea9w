class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # prim-jarnik algorithm:
        # 2 sets: solved & unsolved, unsolved points have a minimum distance to any solved edge
        # after adding each vertex, recalculate distance O(n^2logn)

        def dist(i, j):
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])

        solved = set()
        dists = [dist(i, 0) for i in range(len(points))]

        solved.add(0)
        unsolved = [(dists[i], i) for i in range(len(points))][1:]
        heapq.heapify(unsolved)

        cost = 0
        while len(solved) < len(points):
            min_dist, i = heapq.heappop(unsolved)
            if i in solved:
                continue
            cost += min_dist
            solved.add(i)
            for j in range(len(points)):
                if j in solved:
                    continue
                new_dist = dist(i, j)
                if new_dist < dists[j]:
                    heapq.heappush(unsolved, (new_dist, j))
                    dists[j] = new_dist
        
        return cost
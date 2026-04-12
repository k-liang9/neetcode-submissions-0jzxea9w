class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # prim-jarnik algorithm:
        # 2 sets: solved & unsolved, unsolved points have a minimum distance to any solved edge
        # after adding each vertex, recalculate distance O(n^2logn)

        def dist(i, j):
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])

        n = len(points)
        dists = [dist(i, 0) for i in range(len(points))]
        solved = [False] * n

        cost = 0
        cur_node = 0
        for _ in range(len(points)):
            cost += dists[cur_node]
            solved[cur_node] = True
            next_min = 5000000
            next_node = 0
            for i in range(len(dists)):
                if solved[i]:
                    continue
                dists[i] = min(dist(cur_node, i), dists[i])
                if dists[i] < next_min:
                    next_min = dists[i]
                    next_node = i
            cur_node = next_node
        
        return cost
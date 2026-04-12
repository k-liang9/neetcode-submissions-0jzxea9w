class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m, n = len(heights), len(heights[0])

        def in_range(i, j):
            return 0 <= i < m and 0 <= j < n

        def bfs(src, q):
            while len(q) > 0:
                i, j = q.popleft()
                src[i][j] = True
                for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    r, c = i+dr, j+dc
                    if in_range(r, c) and not src[r][c] and heights[i][j] <= heights[r][c]:
                        q.append([r, c])

        p_src = [[False for i in range(n)] for i in range(m)]
        a_src = [[False for i in range(n)] for i in range(m)]
        p_q = deque()
        a_q = deque()
        for i in range(m):
            p_q.append([i, 0])
            a_q.append([i, n-1])

        for i in range(n):
            p_q.append([0, i])
            a_q.append([m-1, i])

        bfs(p_src, p_q)
        bfs(a_src, a_q)

        res = []
        for i in range(m):
            for j in range(n):
                if a_src[i][j] and p_src[i][j]:
                    res.append([i, j])

        return res
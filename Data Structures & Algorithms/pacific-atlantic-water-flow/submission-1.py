class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        m = len(heights)
        n = len(heights[0])

        memo = [[0 for i in range(n)] for i in range(m)]
        visited = [[False for i in range(n)] for i in range(m)]

        def in_range(i, j) -> bool:
            return 0 <= i < m and 0 <= j < n

        def dfs(i, j) -> int:
            if visited[i][j]:
                return memo[i][j]

            visited[i][j] = True
            if i == 0 or j == 0:
                memo[i][j] |= 0b1

            if i == m-1 or j == n-1:
                memo[i][j] |= 0b10

            for k in [-1, 1]:
                r = i+k
                c = j
                if in_range(r, c) and heights[r][c] <= heights[i][j]:
                    memo[i][j] |= dfs(r, c)

                r = i
                c = j+k
                if in_range(r, c) and heights[r][c] <= heights[i][j]:
                    memo[i][j] |= dfs(r, c)
            
            for k in [-1, 1]:
                r = i+k
                c = j
                if in_range(r, c) and heights[r][c] == heights[i][j]:
                    memo[r][c] |= memo[i][j]

                r, c = i, j+k
                if in_range(r, c) and heights[r][c] == heights[i][j]:
                    memo[r][c] |= memo[i][j]

            return memo[i][j]

        res = []
        for i in range(m):
            for j in range(n):
                if dfs(i, j) == 0b11:
                    res.append([i, j])

        return res

[7, 7]
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        visited = [[False for i in range(n)] for i in range(m)]

        def dfs(i, j):
            print(i, j)
            if not (0 <= i < m and 0 <= j < n):
                print("out of range")
                return 0
            if grid[i][j] == 0 or visited[i][j]:
                print("visited or water")
                return 0

            print("is land")
            visited[i][j] = True
            return 1 + dfs(i+1, j) + dfs(i-1, j) + dfs(i, j+1) + dfs(i, j-1)

        
        max_area = 0
        for i in range(m):
            for j in range(n):
                max_area = max(dfs(i, j), max_area)

        return max_area
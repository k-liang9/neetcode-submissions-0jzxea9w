class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[False for i in range(n)] for i in range(m)]

        def visit_island(i, j):
            nonlocal visited
            if not (0 <= i < m and 0 <= j < n):
                return
            
            if visited[i][j] or grid[i][j] == '0':
                return

            visited[i][j] = True
            visit_island(i-1, j)
            visit_island(i+1, j)
            visit_island(i, j-1)
            visit_island(i, j+1)
            print(i, j)

        cnt = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and not visited[i][j]:
                    print('new island')
                    cnt += 1
                    visit_island(i, j)

        return cnt
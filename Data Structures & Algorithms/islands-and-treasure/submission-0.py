class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        q = deque()
        m = len(grid)
        n = len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 0:
                    q.append((i+1, j))
                    q.append((i-1, j))
                    q.append((i, j+1))
                    q.append((i, j-1))
        
        dist = 1
        while len(q) > 0:
            size = len(q)
            for k in range(size):
                i, j = q.popleft()
                if 0 <= i < m and 0 <= j < n:
                    if grid[i][j] > dist:
                        grid[i][j] = dist
                        q.append((i+1, j))
                        q.append((i-1, j))
                        q.append((i, j+1))
                        q.append((i, j-1))
                    
            dist += 1
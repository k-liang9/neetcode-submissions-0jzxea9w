class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        q = deque()
        m = len(grid)
        n = len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    q.append((i+1, j))
                    q.append((i-1, j))
                    q.append((i, j+1))
                    q.append((i, j-1))

        mins = 0
        while len(q):
            surface = len(q)
            has_fresh = False
            for k in range(surface):
                i, j = q.popleft()
                if 0 <= i < m and 0 <= j < n:
                    if grid[i][j] == 1:
                        has_fresh = True
                        grid[i][j] = 2
                        q.append((i+1, j))
                        q.append((i-1, j))
                        q.append((i, j+1))
                        q.append((i, j-1))

            if has_fresh:
                mins += 1

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    return -1

        return mins